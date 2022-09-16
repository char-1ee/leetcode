#include "../utils/utility.h"
using namespace std;

class Solution {
public:

    /** Recursive */
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        if (!l || !r ) return false;
        if (l->val != r->val) return false;
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }

    /** Iterative */
    bool isSymmetric2(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q1{{root->left}};
        queue<TreeNode*> q2{{root->right}};
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode* t1 = q1.front(); q1.pop();
            TreeNode* t2 = q2.front(); q2.pop();
            
            if (!t1 && !t2) continue;
            else if (!t1 || !t2) return false;
            
            if (t1->val != t2->val) return false;
            
            q1.push(t1->left);
            q1.push(t1->right);
            q2.push(t2->right);
            q2.push(t2->left);
        }
        return true;
    }
};
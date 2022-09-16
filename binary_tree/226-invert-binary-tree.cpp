#include "../utils/utility.h"
using namespace std;

class Solution {
public:
    /** BFS */
    TreeNode* invertTree2(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            for (int i = 0; i < q.size(); ++i) {
                TreeNode* t = q.front(); q.pop();
                TreeNode* temp = t->left;
                t->left = t->right;
                t->right = temp;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return root;
    }
};

// Recursive
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    
    void invert(TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) return;
        
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        if (root->left) {
            invert(root->left);
        }
        if (root->right) {
            invert(root->right);
        }
        return;
    }
};
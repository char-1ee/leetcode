#include '../utils/utility.h'

class Solution {
public:
    // Recursive
    bool isSameTree1(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // Iterative
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!q || !p) return false;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(p);
        s2.push(q);
        
        while (!s1.empty()) {
            TreeNode* pNode = s1.top(); s1.pop();
            TreeNode* qNode = s2.top(); s2.pop();
            
            if (!check(pNode, qNode)) {
                return false;
            }
            
            if (pNode) {
                s1.push(pNode->left);
                s1.push(pNode->right);
            }
            
            if (qNode) {
                s2.push(qNode->left);
                s2.push(qNode->right);
            }
        }
        return true;
    }

    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return true;
    }
};
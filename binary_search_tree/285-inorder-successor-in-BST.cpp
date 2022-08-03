#include <bits/stdc++.h>
#include "../utils/utility.h"

// Recursive
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return nullptr;

        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode* left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};

// Iterative
class Solution2 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr;

        while (root) {
            if (root->val <= p->val) {
                root = root->right;
            } else {
                res = root;
                root = root->left;
            }
        }
        return res;
    }
};
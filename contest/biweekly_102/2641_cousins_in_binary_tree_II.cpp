#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        unordered_map<int, int> m;  // level : level_sum
        dfs(root, 0, m);
        TreeNode *newRoot = new TreeNode(0);
        dfs2(root, newRoot, 0, m);
        return newRoot;
    }

    // Construct map
    void dfs(TreeNode *node, int level, unordered_map<int, int> &m) {
        if (!node) return;
        m[level] += node->val;
        dfs(node->left, level + 1, m);
        dfs(node->right, level + 1, m);
    }

    // Calculate (from one level up) and replace
    void dfs2(TreeNode *node, TreeNode *curr, int level,
              unordered_map<int, int> &m) {
        int leftVal = node->left ? node->left->val : 0;
        int rightVal = node->right ? node->right->val : 0;
        int cousinSum = m[level + 1] - leftVal - rightVal;
        if (node->left) {
            curr->left = new TreeNode(cousinSum);
            dfs2(node->left, curr->left, level + 1, m);
        }
        if (node->right) {
            curr->right = new TreeNode(cousinSum);
            dfs2(node->right, curr->right, level + 1, m);
        }
    }
};
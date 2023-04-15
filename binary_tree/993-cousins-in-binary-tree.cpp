/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    bool isCousins(TreeNode *root, int x, int y) {
        unordered_map<int, pair<int, int>> m;  // val : pair<depth, parent>
        helper(root, 0, -1, m);
        return m[x].first == m[y].first && m[x].second != m[y].second;
    }

    // Construct map
    void helper(TreeNode *node, int level, int parent,
                unordered_map<int, pair<int, int>> &m) {
        if (!node) return;
        m[node->val] = make_pair(level, parent);
        helper(node->left, level + 1, node->val, m);
        helper(node->right, level + 1, node->val, m);
    }
};

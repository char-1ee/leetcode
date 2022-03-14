/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);
        vector<vector<int>> reverse{res.rbegin(), res.rend()};
        return reverse;
    }
    
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) return;
        if (res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        if (root->left) levelOrder(root->left, level + 1, res);
        if (root->right) levelOrder(root->right, level + 1, res);
    }
};
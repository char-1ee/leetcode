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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int lo, int hi) {
        if (lo > hi) return {nullptr};
        vector<TreeNode*> res;
        for (int i = lo; i <= hi; ++i) {
            vector<TreeNode*> leftSubTree = generateTrees(lo, i-1);
            vector<TreeNode*> rightSubTree = generateTrees(i+1, hi);
            for (TreeNode* leftRoot : leftSubTree) {
                for (TreeNode* rightRoot : rightSubTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
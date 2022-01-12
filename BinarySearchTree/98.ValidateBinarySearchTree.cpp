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
    /** Recursive method 1 */
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long lo, long hi) {
        if (!root) return true;
        if (root->val > lo && root->val < hi)
            return isValidBST(root->left, lo, root->val) && isValidBST(root->right, root->val, hi);
        return false;
    }

    /** Recursive method 2 */
    bool isValidBST2(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root) return true;
        if (min && root->val <= min->val) return false;
        if (max && root->val >= max->val) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
    bool isValidBST2(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
};
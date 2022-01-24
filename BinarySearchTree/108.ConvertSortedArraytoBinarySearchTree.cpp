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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return new TreeNode(nums[0]);
        TreeNode* root = helper(nums, 0, n);
        return root;
    }
    
    TreeNode* helper(vector<int>& nums, int lo, int hi) {
        if (hi <= lo) return NULL;
        int mid = lo + (hi - lo) / 2;
        TreeNode* t = new TreeNode(nums[mid]);
        t->left = helper(nums, lo, mid);
        t->right = helper(nums, mid + 1, hi);
        return t;
    }
};
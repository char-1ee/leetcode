class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, -1, ans);
        return ans;
    }
    
    int dfs(TreeNode* root, int d, int& ans) {
        if (!root) return 0;
        int left = dfs(root->left, 0, ans);
        int right = dfs(root->right, 1, ans);
        ans = max({left, right, ans});
        
        return d ? left + 1 : right + 1;
    }
};
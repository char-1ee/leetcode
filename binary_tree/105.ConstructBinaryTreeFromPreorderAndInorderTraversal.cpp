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
    TreeNode* buildTree(vector<int>& pre, int pre_left, int pre_right, vector<int>& in, int in_left, int in_right) {
       
        if (pre_left > pre_right || in_left > in_right) return nullptr;
        
        int i = 0;
        for (i = in_left; i <= in_right; ++i) {
            if (in[i] == pre[pre_left]) break;
        }
        TreeNode* root = new TreeNode(pre[pre_left]);
        root->left = buildTree(pre, pre_left + 1, pre_left + i - in_left, in, in_left, i - 1);
        root->right = buildTree(pre, pre_left + i - in_left + 1, pre_right, in, i + 1, in_right);
        return root;
    };
    

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {     
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
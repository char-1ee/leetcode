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
    
    TreeNode* buildTree(vector<int>& inorder, int iLeft, int iRight, vector<int>& postorder, int pLeft, int pRight) {
      
        if (iLeft > iRight || pLeft > pRight) return nullptr;
        
        int i = iLeft;
        while (inorder[i] != postorder[pRight]) i++;
        
        TreeNode* root = new TreeNode(postorder[pRight]);
        root->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1);
        root->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
        return root;
    };
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
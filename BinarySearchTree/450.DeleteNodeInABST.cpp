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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val > key) root->left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else {  // careful about the if-else paradiam
            if (!root->left) root = root->right;
            else if (!root->right) root = root->left;           
            else {
                TreeNode* curr = root->right;
                while (curr->left) curr = curr->left;
                root->val = curr->val;
                root->right = deleteNode(root->right, curr->val);
            }
        }
        return root;
    }
};
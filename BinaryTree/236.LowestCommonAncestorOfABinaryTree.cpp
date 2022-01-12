/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // if current node equals p, q, means q,p are found;
        // if current node is null, means p, q not found in current substree and can return back
        if (!root || root == p || root == q) return root;

        // common recursive calls to binary tree 
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root; // if p, q are allocated in left and right subtrees repectively
        return left ? left : right;     // if p, q found in a same side subtree, return which is higher 
    }
};
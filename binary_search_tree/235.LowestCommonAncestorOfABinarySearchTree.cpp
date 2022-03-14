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

    /** Recursive method 1: Conditions on current->val by BST properties */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val > max(p->val, q->val)) 
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        else 
            return root;
    }

    /** Recursive method 2: Common for all Binary Tree */
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right; 
    }

    /** Iterative method */
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val > max(p->val, q->val)) root = root->left;
            else if (root->val < min(p->val, q->val)) root = root->right;
            else break;
        }
        return root;
    }
};
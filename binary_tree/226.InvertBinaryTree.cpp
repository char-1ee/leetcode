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
    /** BFS */
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int size = q.size();
            vector<int> arr; // contains current level nodes
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front(); q.pop();
                TreeNode* temp = t->left;
                t->left = t->right;
                t->right = temp;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return root;
    }

    /** Recursive */
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};
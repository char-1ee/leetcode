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
    /** Iterative method 1*/
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* p = root;

        while (!p || !s.empty()) {
            if (!p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top(); s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }

    /** Iterative method 2 */
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }

    /** Recursive */
    vector<int> res;
    vector<int> inorderTraversalRe(TreeNode* root) {
        inHelper(root);
        return res;
    }

    void inHelper(TreeNode* p) {
        if (!p) return;
        inHelper(p->left);
        res.push_back(p->val);
        inHelper(p->right);
    }
}
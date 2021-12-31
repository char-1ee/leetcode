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
    /** Iterative with stack */
    vector<int> postTraversal(TreeNode* root) {
        if (!root) return {};

        stack<TreeNode*> s1{{root}};
        stack<TreeNode*> s2;
        vector<int> res;

        while (!s1.empty()) {
            TreeNode* p = s1.top(); s1.pop();
            s2.push(p);
            if (p->left) s1.push(p->left);
            if (p->right) s1.push(p->right);
        }
        while (!s2.empty()) {
            TreeNode* p2 = s2.top(); s2.pop();
            res.push_back(p2->val);
        }
        return res;
    }

    /** Recursive */
    vector<int> res;
    vector<int> postTraversalRe(TreeNode* root) {
        postHelper(root);
        return res;
    }

    void postHelper(TreeNode* root) {
        if (!root) return;
        postHelper(root->left);
        postHelper(root->right);
        res.push_back(root->val);
    }
}
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

    /** Iterative method 1 */
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {}
        
        stack<TreeNode*> s;
        vector<int> res;
        s.push(root);

        while (!s.empty()) {
            TreeNode* p = s.top(); s.pop();
            res.push_back(p->val);
            if (p->right) s.push(p->left);
            if (p->left) s.push(p->right);
        }
        return res;
    } 

    /** Iterative method 2 */
    vector<int> preorderTraversal2(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* p = root;
        while (p || !s.empty()) {
            while (p) {
                res.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            p = p->right;
        }
        return res;
    }

    /** Recursive method 1 */
    vector<int> res;

    vector<int> preorderTraversalRe1(TreeNode* root) {
        preHelper(root);
        return res;
    }
    void preHelper(TreeNode* root) {
        if (!root) return;
        res.push_back(root->val);
        preHelper(root->left);
        preHelper(root->right);
    }

    /** Recursive method 2 */
    vector<int> preorderTraversalRe2(TreeNode* root) {
        if (!root) return;
        re.push_back(root->val);
        preorderTraversalRe2(root->left);
        preorderTraversalRe2(root->right);
        return res;
    }
};
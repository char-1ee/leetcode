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

    /** Iterative */
    vector<vector<int>> levelOrderIterative(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {    // loop outer level 
            vector<int> row;    // contains inner level nodes
            int len = q.size(); // size of inner level

            for (int i = 0; i < len; ++i) { // loop inner level
                TreeNode* p = q.front();
                q.pop();
                row.push_back(p->val);

                // preapre for next inner level 
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            res.push_back(row);
        }
        return res;
    }

    /** Recursive */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);
        return res;
    }
    
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) return;
        if (res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        if (root->left) levelOrder(root->left, level + 1, res);
        if (root->right) levelOrder(root->right, level + 1, res);
    }
}
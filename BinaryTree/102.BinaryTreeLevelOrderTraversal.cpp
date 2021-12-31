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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
}
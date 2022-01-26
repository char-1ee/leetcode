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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        queue<int> q1;
        queue<int> q2;
        dfs(root1, q1);
        dfs(root2, q2);
        
        while (!q1.empty() && !q2.empty()) {
            if (q1.front() > q2.front()) {
                res.push_back(q2.front());
                q2.pop();
            } else {
                res.push_back(q1.front());
                q1.pop();
            }
        }
        
        while (!q1.empty()) {
            res.push_back(q1.front());
            q1.pop();
        }
        
        while (!q2.empty()) {
            res.push_back(q2.front());
            q2.pop();
        }
        
        return res;
    }
    
    void dfs(TreeNode* root, queue<int>& q) {
        if (!root) return;
        dfs(root->left, q);
        q.push(root->val);
        dfs(root->right, q);
    }
//=====================================================================

    /** One time pass by BST iterator */
    vector<int> getAllElements2(TreeNode* root1, TreeNode* root2) {
            pushLeft(root1, s1);
            pushLeft(root2, s2);
            while (!s1.empty() || !s2.empty()) {
                stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : 
                s1.top()->val < s2.top()->val ? s1 : s2;
                auto n = s.top(); s.pop();
                res.push_back(n->val);
                pushLeft(n->right, s);
            }
            return res;
        }
    
private:
    stack<TreeNode*> s1, s2;
    vector<int> res;
    
    void pushLeft(TreeNode* root, stack<TreeNode*>& s) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
//=======================================================================

};
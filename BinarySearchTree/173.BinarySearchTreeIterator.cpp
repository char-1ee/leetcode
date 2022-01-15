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
class BSTIterator {
private:
    stack<TreeNode*> s;
    
    void pushLeftSubtree(TreeNode* x) {
        while (x) {
            s.push(x);
            x = x->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushLeftSubtree(root);
    }
    
    int next() {
        TreeNode* next = s.top(); s.pop();
        if (next->right)
            pushLeftSubtree(next->right);
        return next->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
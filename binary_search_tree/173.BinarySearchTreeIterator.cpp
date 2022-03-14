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

/** 
 * Constaints: next() and hasNext(): time in AVERAGE O(1) and space in O(logN) (height of tree)
 */
class BSTIterator {
private:
    // use stack to contain all node in left subtree,
    // so that at any instant of time the stack contains elements equal to the height of the tree.
    stack<TreeNode*> s;
    
    // because push left substree is regarded as partial operations
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
    
    // average time O(1): If we iterate whole tree, every node just goes into stack once and is goes out once， so it's O(2) for each node.
    // refer to https://leetcode.com/problems/binary-search-tree-iterator/discuss/52526/Ideal-Solution-using-Stack-(Java)
    int next() {
        TreeNode* next = s.top(); s.pop();
        if (next->right)
            pushLeftSubtree(next->right);
        return next->val;
    }
    
    // time O(1)
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
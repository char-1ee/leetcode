class Solution {
public:
    /** Recursive */
    bool hasPathSum1(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum ) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }

    /** Iterative */
    bool hasPathSum2(TreeNode* root, int targetSum) {
        if (!root) return false;
        stack<TreeNode*> s{{root}};
        while (!s.empty()) {
            TreeNode* t = s.top(); s.pop();
            if (!t->left && !t->right) {
                if (t->val == targetSum)
                    return true;
            }
            if (t->left) {
                t->left->val += t->val;
                s.push(t->left);
            }
            if (t->right) {
                t->right->val += t->val;
                s.push(t->right);
            }
        }
        return false;
    }
};
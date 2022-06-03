#include "../utils/utility.h"

class Solution1 {
public:
    int res = 0; 
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) { 
            return 0; 
        } 
        if (isUnival(root, root->val)) {
            res++;
        }
        countUnivalSubtrees(root->left);
        countUnivalSubtrees(root->right);
        return res;
    }
    
    bool isUnival(TreeNode* root, int val) {
        if (!root) return true;
        return root->val == val && isUnival(root->left, val) && isUnival(root->right, val);
    }
};

class Solution2 {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        isUnival(root, -1, res);
        return res;
    }
    
    bool isUnival(TreeNode* root, int val, int& res) {
        if (!root) return true;

        // If left subtree or right subtree not uni-value, return false.
        // using | rather than ||: to ensure both sides get calculated (++res)
        if (!isUnival(root->left, root->val, res) | !isUnival(root->right, root->val, res)) {
            return false;
        }
        ++res;
        return root->val == val;
    }
};

class Solution3 {
    public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        int cnt = 0;
        helper(root, cnt);
        return cnt;
    }
    
    bool helper(TreeNode* root, int& cnt) {
        if (root == nullptr) {
            return true;
        }
        
        bool _left = helper(root->left, cnt);
        bool _right = helper(root->right, cnt);
        
        if (_left && _right) {
            if (root->left && root->val != root->left->val) {
                return false;
            }
            if (root->right && root->val != root->right->val) {
                return false;
            }
            ++cnt;
            return true;
        }
        return false;
    }
}


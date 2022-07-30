#include <bits/stdc++.h>
#include "../utils/utility.h"

using namespace std;

// Bottom-up. time O(n) space O(n)
class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedCore(root) != -1;
    }

    int isBalancedCore(TreeNode* root) {
        if (!root) return 0;

        int left = isBalancedCore(root->left);
        if (left == -1) return -1;
        int right = isBalancedCore(root->right);
        if (right == -1) return -1;

        int diff = abs(left - right);
        if (diff > 1) return -1;

        return 1 + max(left, right);
    }
};

// Bottom-up 2. time O(n) space O(n)
class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, depth);
    }

    bool isBalanced(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return true;
        }

        int left_depth, right_depth;
        int flag = isBalanced(root->left, left_depth) && isBalanced(root->right, right_depth);
        if (flag) {
            int diff = abs(left_depth - right_depth);
            if (diff <= 1) {
                depth = 1 + max(left_depth, right_depth);
                return true;
            }
        }
        return false;
    }
};

// Top-down recursion. time O(nlogn) space O(n)
class Solution3 {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int left = getDepth(root->left);
        int right = getDepth(root->right);
        int diff = abs(left - right);
        if (diff > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getDepth(TreeNode* root) {
        if (!root) return 0;

        int left = getDepth(root->left);
        int right = getDepth(root->right);

        return 1 + max(left, right);
    }
};
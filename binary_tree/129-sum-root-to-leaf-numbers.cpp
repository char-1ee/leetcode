#include <bits/stdc++.h>

#include "../utils/utility.h"
using namespace std;

class Solution {
   public:
    int sumNumbers(TreeNode *root) { return dfs(root, 0); }

    int dfs(TreeNode *root, int sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        }
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
};
#include <bits/stdc++.h>
#include "../utils/utility.h"
using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }

    int maxDepth(TreeNode* root, int& diameter) {
        if (!root) return 0;
        int left_depth = maxDepth(root->left, diameter);
        int right_depth = maxDepth(root->right, diameter);

        diameter = max(diameter, left_depth + right_depth);
        return 1 + max(left_depth, right_depth);
    }
};

// Memorisation
class SolutionDP {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }

    int maxDepth(TreeNode* root, int& diameter) {
        if (!root) return 0;
        if (m.count(root)) return m[root];
        int left_depth = maxDepth(root->left, diameter);
        int right_depth = maxDepth(root->right, diameter);

        diameter = max(diameter, left_depth + right_depth);
        m[root] = 1 + max(left_depth, right_depth);
        return m[root];
    }

private:
    unordered_map<TreeNode*, int> m;
};
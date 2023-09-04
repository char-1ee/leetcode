#include <bits/stdc++.h>

#include "../utils/utility.h"
using namespace std;

// Check if given tree is Perfect Tree, if yes, then calculate, otherwise find
// one level by one level
class Solution_1 {
   public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        TreeNode *pLeft = root;
        TreeNode *pRight = root;

        int nLeft = 0, nRight = 0;
        while (pLeft) {
            nLeft++;
            pLeft = pLeft->left;
        }
        while (pRight) {
            nRight++;
            pRight = pRight->right;
        }
        if (nLeft == nRight) return pow(2, nLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// Binary Search O(h^2)
class Solution_2 {
   public:
    int getLeftDepth(TreeNode *root) {
        int d = 0;
        while (root) {
            d++;
            root = root->left;
        }
        return d;
    }

    bool exist(TreeNode *root, int idx, int h) {
        int l = 0, r = (int)pow(2, h) - 1;
        for (int i = 0; i < h; i++) {
            int mid = l + (r - l) / 2;
            if (idx <= mid) {
                root = root->left;
                r = mid;
            } else {
                root = root->right;
                l = mid + 1;
            }
        }
        return root != nullptr;
    }

    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int h = getLeftDepth(root);
        if (h == 0) return 1;

        int l = 1, r = (int)pow(2, h) - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (exist(root, mid, h))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return (int)pow(2, h) - 1 + l;
    }
};

// https://leetcode.com/problems/count-complete-tree-nodes/solutions/61958/concise-java-solutions-o-log-n-2/
class Solution_3 {
   public:
    int depth(TreeNode *t) { return t == nullptr ? -1 : 1 + depth(t->left); }

    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int h = depth(root), cnt = 0;
        while (root) {
            if (depth(root->right) == h - 1) {
                root = root->right;
                cnt += (1 << h);
            } else {
                root = root->left;
                cnt += 1 << (h - 1);
            }
            h--;
        }
        return cnt;
    }
};

// Complete BT: from 0 to h-1 level, all nodes have 2 children
// 而且每一层有相同的depth. 第h层的leaf nodes向左靠齐 Perfect BT: 全满对称 Full
// BT: 一个node有child就必然有2个子节点
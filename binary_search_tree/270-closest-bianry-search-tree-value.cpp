#include <bits/stdc++.h>
#include '../utils/TreeNode.h'

class Solution {
public:
    // ============= method 1: O(N) ================
    int closestValue_1(TreeNode* root, double target) {       
        vector<int> vals;
        inorder(root, vals);

        int res = INT_MAX;
        for (int val : vals) {
            if (abs(val - target) >= abs(res - target)) {
                break;
            } 
            res = val;
        }
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    // =============== method 2: O(H) ================
     int closestValue_2(TreeNode* root, double target) {
        int res = root->val;
        while (root) {
            int val = root->val;
            if (abs(target - val) < abs(target - res)) {
                res = val;
            }
            root = root->val > target ? root->left : root->right;
        }
        return res;
    }
};
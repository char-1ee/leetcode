#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int n = arr.size(), mx = 1;
        unordered_map<int, int> dp;
        // dp(x) stands for the LAS that ends with element x (not index)

        for (auto &num : arr) {
            dp[num] = dp[num - difference] + 1;
            mx = max(mx, dp[num]);
        }
        return mx;
    }
};
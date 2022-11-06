#include <bits/stdc++.h>
using namespace std;

// Top-down DP
// f(currIdx, k) = min(max(sum(currIdx, i) + f(i + 1, k - 1))
class Solution {
public:
    vector<vector<int>> cache{1001, vector<int>(51, -1)};
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return dp(0, k, prefix);
    }
    
    // currIdx: a new subarray from currIdx,
    // k: count of subarrays left 
    // prefix: prefix sums for calculation sum(i, j)
    int dp(int currIdx, int k, vector<int>& prefix) {
        int n = prefix.size() - 1;
        
        if (cache[currIdx][k] != -1) {
            return cache[currIdx][k];
        }
        
        if (k == 1) {
            cache[currIdx][1] = prefix[n] - prefix[currIdx];
            return cache[currIdx][1];
        }
        
        int res = INT_MAX;
        for (int i = currIdx; i <= n - k; i++) {
            int iSum = prefix[i + 1] - prefix[currIdx];
            int mxSum = max(iSum, dp(i + 1, k - 1, prefix));
            res = min(res, mxSum);
            if (iSum >= res) break;
        }
        
        return cache[currIdx][k] = res;
    }
};

// 1. For each element, it has two status/operations/decisions: 
//      added into the current subarray
//      used as the new start of next subarray.
// Each decision of an element depends on previous decision we made, because adding an element into current subarray depends on number of subarrays we have now.
// 2. The goal is to minimize the largest sum of subarrays. (Find extreme values or find optimal solutions)
// In conclusion from 1 and 2 -> DP

// Bottom-up DP
class Solution2 {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        vector<vector<long>> dp(k + 1, vector<long>(n + 1, LONG_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = i - 1; k < j; k++) {
                    long mx = max(prefix[j] - prefix[k], dp[i - 1][k]);
                    dp[i][j] = min(dp[i][j], mx);
                }
            }
        }
        return dp[k][n];
    }
};
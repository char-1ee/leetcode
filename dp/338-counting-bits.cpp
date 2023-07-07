#include <bits/stdc++.h>
using namespace std;

// DP, O(n), O(1)
class Solution_1 {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            dp[i] = dp[i / 2] + i % 2;
        }
        return dp;  
    }
};

// DP2
class Solution_2 {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};

// For DP solutions, key point is to find the math relationship,
// which should have a 1-to-1 reflection, such that cover all index [1, n]
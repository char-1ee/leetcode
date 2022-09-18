#include <bits/stdc++.h>

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;

        int mod = 1e9 + 7;
        std::vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 3] + 2 * dp[i - 1]) % mod;
        }
        return dp[n];
    }
};
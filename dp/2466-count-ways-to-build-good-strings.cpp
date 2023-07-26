#include <bits/stdc++.h>
using namespace std;

#define N 1000010

// Recursive, more intutive
class Solution {
    const int MOD = 1e9 + 7;
    int dp[N];

   public:
    int count(int end, int zero, int one) {
        if (dp[end] > -1) return dp[end];

        int cnt = 0;
        if (end >= zero) {
            cnt += count(end - zero, zero, one);
        }
        if (end >= one) {
            cnt += count(end - one, zero, one);
        }
        dp[end] = cnt % MOD;
        return dp[end];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, N);
        dp[0] = 1;
        int res = 0;

        for (int i = low; i <= high; i++) {
            res += count(i, zero, one);
            res %= MOD;
        }
        return res;
    }
};

// Iterative
class Solution2 {
   public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int MOD = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= high; i++) {
            if (i >= zero) {
                dp[i] += dp[i - zero];
            }
            if (i >= one) {
                dp[i] += dp[i - one];
            }
            dp[i] %= MOD;
        }

        int res = 0;
        for (int end = low; end <= high; end++) {
            res += dp[end];
            res %= MOD;
        }
        return res;
    }
};
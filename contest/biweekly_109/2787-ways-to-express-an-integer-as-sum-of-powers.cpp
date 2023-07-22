#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[301][301];
    const int MOD = 1e9 + 7;

   public:
    int f(int n, int x, int num) {
        if (dp[n][num] > 0) {
            return dp[n][num];
        }

        int val = n - pow(num, x);
        if (val == 0) return 1;
        if (val < 0) return 0;

        int res = (f(val, x, num + 1) + f(n, x, num + 1)) % MOD;
        dp[n][num] = res;
        return res;
    }

    int numberOfWays(int n, int x) {
        memset(dp, 0, 301 * 301);
        return f(n, x, 1);
    }
};
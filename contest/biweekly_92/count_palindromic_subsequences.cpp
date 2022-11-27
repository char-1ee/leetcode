#include <bits/stdc++.h>
using namespace std;

// length 5: find head and end char pair, then count 3-length
class Solution {
   public:
    int countPalindromes(string s) {
        long ans = 0;
        int MOD = 1e9 + 7;
        int len = s.length();
        vector<vector<long>> dp(len, vector<long>(len, 0));

        for (int i = len - 2; i >= 0; --i) {
            for (int j = i + 2; j < len; ++j) {
                dp[i][j] =
                    dp[i][j - 1] + (dp[i + 1][j] == dp[i + 1][j - 1]
                                        ? 0
                                        : dp[i + 1][j] - dp[i + 1][j - 1]);
                if (s[i] == s[j]) {
                    dp[i][j] += j - i - 1;
                }
            }
        }

        for (int i = 0; i < len; ++i) {
            for (int j = i + 4; j < len; ++j) {
                if (s[i] == s[j]) {
                    ans += dp[i + 1][j - 1];
                }
            }
        }
        return (int)(ans % MOD);
    }
};

class Solution2 {
   public:
    int pre[10000][10][10], suf[10000][10][10], cnts[10] = {};

    // XY_YX
    int countPalindromes(string s) {
        int n = s.size(), ans = 0, MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';
            if (i > 0) {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        pre[i][j][k] = pre[i - 1][j][k];
                        if (k == c) pre[i][j][k] += cnts[j];
                    }
                    cnts[c]++;
                }
            }
        }
        memset(cnts, 0, sizeof(cnts));
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - '0';
            if (i < n - 1) {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        suf[i][j][k] = suf[i + 1][j][k];
                        if (k == c) suf[i][j][k] += cnts[j];
                    }
                    cnts[c]++;
                }
            }
        }
        for (int i = 2; i < n - 2; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    ans =
                        (ans + 1LL * pre[i - 1][j][k] * suf[i + 1][j][k]) % MOD;
                }
            }
        }
        return ans;
    }
};
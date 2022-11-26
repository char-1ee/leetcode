#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countPalindromes(string s) {
        long ans = 0;
        int MOD = 10e9 + 7;
        int len = s.length();
        vector<vector<long>> dp(len, vector<long>(len, 0));

        for (int i = len - 2; i >= 0; --i) {
            for (int j = i + 2; j < len; ++j) {
                dp[i][j] =
                    dp[i][j - 1] + (dp[i + 1][j] == dp[i + 1][j - 1] ? 0 : dp[i + 1][j] - dp[i + 1][j - 1]);
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
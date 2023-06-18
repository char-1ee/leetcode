#include <bits/stdc++.h>
using namespace std;

// String manipulation
class Solution_1 {
   public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length(), i = 0, j = 0;
        // iStart: position that * matchs to in s
        // jStart: position of * in p
        int iStart = -1, jStart = -1;
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++, j++;
            } else if (j < n && p[j] == '*') {
                iStart = i;
                jStart = j++;
            } else if (iStart >= 0) {
                j = jStart + 1;
                i = ++iStart;
            } else
                return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};

// Dp
class Solution_2 {
   public:
    // dp[i][j] 表示 s中前i个字符组成的子串和p中前j个字符组成的子串是否能匹配
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') &&
                               dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
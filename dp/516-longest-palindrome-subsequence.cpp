#include <bits/stdc++.h>
using namespace std;

// Iterative DP
class Solution_1 {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        // f(i, j): the lps between i and j
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        return LPS(s, 0, n - 1, dp);
    }

    int LPS(string& s, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j]) return dp[i][j];
        if (i > j) return 0;
        if (i == j) dp[i][j] = 1;

        if (s[i] == s[j]) {
            dp[i][j] = 2 + LPS(s, i + 1, j - 1, dp);
        } else {
            dp[i][j] = max(LPS(s, i + 1, j, dp), LPS(s, i, j - 1, dp));
        }
        return dp[i][j];
    }
};
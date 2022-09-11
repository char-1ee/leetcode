#include <bits/stdc++.h>
using namespace std;

// DP solution 1
// Time O(mn) single pass, space O(mn)
class Solution1 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int dp[m][n];
        int maxL = 0;
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
                maxL = max(maxL, dp[i][j]);
            }
        }
        return maxL * maxL;
    }
};

// DP solution 2
// Time O(mn) space O(n)
class firstMissingPositive_solution2 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dp(n + 1, 0);
        int prev = 0; // (i - 1, j - 1) for (i, j)
        int maxL = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(dp[j], min(dp[j - 1], prev)) + 1;
                    maxL = max(maxL, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = tmp;
            }
        }
        return maxL * maxL;
    }
};
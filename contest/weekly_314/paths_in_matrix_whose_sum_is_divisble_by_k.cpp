#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k)));
        dp[1][1][grid[0][0] % k] = 1;

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (i == 1 && j == 1) continue;
                for (int r = 0; r < k; r++) {
                    dp[i][j][(r + grid[i - 1][j - 1]) % k] =
                        (dp[i - 1][j][r] + dp[i][j - 1][r]) % MOD;
                }
            }
        }

        return dp[m][n][0];
    }
};
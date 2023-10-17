#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double champagneTower(int n, int query_row, int query_glass) {
        vector<vector<double>> dp(110, vector<double>(110, 0));
        dp[0][0] = n;

        for (int r = 0; r <= query_row; r++) {
            for (int c = 0; c <= query_glass; c++) {
                double t = (dp[r][c] - 1) / 2.0;
                if (t > 0) {
                    dp[r + 1][c] += t;
                    dp[r + 1][c + 1] += t;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }

    // Optimized one
    double champagneTower_2(int n, int query_row, int query_glass) {
        vector<double> dp(110, 0);
        dp[0] = n;

        for (int r = 1; r <= query_row; r++) {
            for (int c = r; c >= 0; c--) {
                double t = (dp[c] - 1 ) / 2.0;
                if (t > 0) {
                    dp[c] = t;
                    dp[c + 1] += t;
                } else {
                    dp[c] = 0;
                }
            }
        }
        return min(1.0, dp[query_glass]);
    }
};
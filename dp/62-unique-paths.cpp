#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Math, but overflow for large products
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        int res = 1;
        if (m < n) {
            int tmp = m;
            m = n;
            n = tmp;
        }
        
        for (int i = 0; i < m - 1; i++) {
            res *= n + i;
            res /= i + 1;
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long mostPoints(vector<vector<int>> &questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            long long skip = questions[i][0];
            if (i + 1 + questions[i][1] < n) {
                skip += dp[i + 1 + questions[i][1]];
            }
            dp[i] = max(dp[i + 1], skip);
        }
        return dp[0];
    }
};
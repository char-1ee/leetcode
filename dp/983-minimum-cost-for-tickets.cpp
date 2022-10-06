#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366);
        unordered_set<int> set(days.begin(), days.end());
        dp[0] = 0;

        for (int i = 1; i <= 365; i++) {
            dp[i] = dp[i - 1];
            if (set.count(i)) {
                int day = dp[i - 1] + costs[0];
                int week = dp[max(0, i - 7)] + costs[1];
                int month = dp[max(0, i - 30)] + costs[2];
                dp[i] = min(day, min(week, month));
            }
        }
        return dp[365];
    }
};

class Solution2 {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n + 1; i++) {
            dp[i] = min(dp[i - 1] + costs[0], dp[i]);
            for (int j = 1; j <= i; j++) {
                if (days[j - 1] + 7 > days[i - 1]) {
                    dp[i] = min(dp[i], dp[j - 1] + costs[1]);
                }
                if (days[j - 1] + 30 > days[i - 1]) {
                    dp[i] = min(dp[i], dp[j - 1] + costs[2]);
                }
            }
        }

        return dp[n];
    }
};
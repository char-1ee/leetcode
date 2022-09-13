#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if (n < 2) return k;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k * k;

        for (int i = 3; i <= n; i++) {
            dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
};

class Solution2 {
public:
    int numWays(int n, int k) {
        if (n < 2) return k;

        int last2 = k;
        int last1 = k * k;

        for (int i = 3; i <= n; i++) {
            int curr = (k - 1) * (last1 + last2);
            last2 = last1;
            last1 = curr;
        }
        return last1;
    }
};
#include <bits/stdc++.h>
using namespace std;

// DP: O(n^2), O(n)
class Solution {
   public:
    int findLongestChain(vector<vector<int>> &pairs) {
        int mx = 1, n = pairs.size();
        auto comp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        };
        sort(pairs.begin(), pairs.end(), comp);

        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][1] < pairs[j][0]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            mx = max(dp[i], mx);
        }
        return mx;
    }
};

// Greedy, O(nlogn), O(1)
class Solution2 {
   public:
    int findLongestChain(vector<vector<int>> &pairs) {
        auto comp = [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        };
        // sort by tail
        sort(pairs.begin(), pairs.end(), comp);

        int res = 0, curr = INT_MIN;  // curr: current tail of chain,
        for (auto &p : pairs) {
            if (p[0] > curr) {
                res++;
                curr = p[1];
            }
        }
        return res;
    }
};
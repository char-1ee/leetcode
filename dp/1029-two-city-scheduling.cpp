#include <bits/stdc++.h>
using namespace std;

// Greedy
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), res = 0;
        vector<int> refund;
        for (auto cost : costs) {
            res += cost[0];
            refund.push_back(cost[1] - cost[0]);
        }

        sort(refund.begin(), refund.end());
        for (int i = 0; i < n / 2; i++) {
            res += refund[i];
        }
        return res;
    }
};
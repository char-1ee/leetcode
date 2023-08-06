#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumSeconds(vector<int> &nums) {
        int n = nums.size(), res = INT_MAX;
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto e : mp) {
            int num = e.first;
            vector<int> idx = e.second;
            idx.push_back(idx[0] + n);

            int seconds = 0;
            for (int i = 1; i < idx.size(); i++) {
                int gap = idx[i] - idx[i - 1];
                seconds = max(gap / 2, seconds);
            }

            res = min(res, seconds);
        }
        return res;
    }
};
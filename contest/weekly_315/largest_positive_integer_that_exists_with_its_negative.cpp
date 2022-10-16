#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int res = -1;
        for (auto num : nums) {
            if (num > 0 && set.count(-num))
                res = max(res, num);
        }
        return res;
    }
};
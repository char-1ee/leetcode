#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        long long res = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int start =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
                nums.begin();
            int end =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                1 - nums.begin();
            res += (end - start + 1);
        }
        return res;
    }
};
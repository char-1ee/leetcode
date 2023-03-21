#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(vector<int> &nums, int threshold, int x) {
        int res = 0;
        for (auto num : nums) {
            res += (num + x - 1) / x;
        }
        return res <= threshold;
    }

    int smallestDivisor(vector<int> &nums, int threshold) {
        int n = nums.size();
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, threshold, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
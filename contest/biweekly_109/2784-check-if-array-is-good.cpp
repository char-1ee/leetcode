#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isGood(vector<int> &nums) {
        int n = nums.size(), i;
        sort(nums.begin(), nums.end());

        for (i = 0; i < n - 1; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        return nums[i] == i;
    }
};
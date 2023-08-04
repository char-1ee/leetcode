#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size(), res = nums[0];
        int max_so_far = nums[0];
        int min_so_far = nums[0];

        for (int i = 1; i < n; i++) {
            int t = max_so_far;
            max_so_far =
                max({max_so_far * nums[i], nums[i], min_so_far * nums[i]});
            min_so_far = min({t * nums[i], nums[i], min_so_far * nums[i]});
            res = max(max_so_far, res);
        }
        return res;
    }
};
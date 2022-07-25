#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Negative marking. time O(n), space O(1)
    int findDuplicate_solution1(vector<int>& nums) {
        int dup = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]);
            if (nums[idx] < 0) {
                dup = idx;
                break;
            }

            // Three ways of negate a integer (though compiler optimize for u)
            // 1. nums[i] *= 1.             More readable, simiar speed and space to method 2.
            // 2. nums[i] = -nums[i].       Simiar speed and space to method 1.
            // 3. nums[i] = ~nums[i] + 1.   Save time but increase space.

            nums[idx] *= -1;
        }

        // restore the array (not modify the original array)
        for (int& num : nums) {
            num = abs(num);
        }
        return dup;
    }

    
};
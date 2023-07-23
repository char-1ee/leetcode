#include <bits/stdc++.h>
using namespace std;

// Odd-even 2 var DP
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        long long odd, even;
        if (nums[0] % 2) {
            odd = nums[0], even = nums[0] - x;
        } else {
            odd = nums[0] - x, even = nums[0];
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] % 2) {
                odd = nums[i] + max(odd, even - x);
            } else {
                even = nums[i] + max(even, odd - x);
            }
        }
        return max(odd, even);
    }
};

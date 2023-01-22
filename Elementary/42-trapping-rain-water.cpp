#include <bits/stdc++.h>
using namespace std;

// solution 1: dp
// DP is coming from thw brute force idea which is to iteratively
// find left_max and right_max starting from current index i.
class Solution {
   public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> left(n), right(n);
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1, j = n - 2; i < n; i++, j--) {
            left[i] = max(height[i], left[i - 1]);
            right[j] = max(height[j], right[j + 1]);
        }
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            res += min(left[i], right[i]) -
                   height[i];  // (max_h - curr_h) * width_1
        }
        return res;
    }
};

// solution 2: two pointers
class Solution2 {
   public:
    int trap(vector<int> &height) {
        int n = height.size(), res = 0;
        int left = 0, right = n - 1, lmax = 0, rmax = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > lmax)
                    lmax = height[left];
                else
                    res += lmax - height[left];
                left++;
            } else {
                if (height[right] > rmax)
                    rmax = height[right];
                else
                    res += rmax - height[right];
                right--;
            }
        }
        return res;
    }
};
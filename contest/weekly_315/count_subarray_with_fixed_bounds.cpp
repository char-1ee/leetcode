#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int n = nums.size();
        int minIdx = -1, maxIdx = -1; // index of minK and maxK

        for (int i = 0, j = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                minIdx = maxIdx = -1;
                j = i + 1;
            }
            if (nums[i] == minK) minIdx = i;
            if (nums[i] == maxK) maxIdx = i;
            res += max(0, min(minIdx, maxIdx) - j + 1);
        }
        return res;
    }
};
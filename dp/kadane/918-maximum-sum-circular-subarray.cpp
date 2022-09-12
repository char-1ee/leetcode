#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = nums[0];
        int maxSum = nums[0], currMax = nums[0];
        int minSum = nums[0], currMin = nums[0];

        for (int i = 1; i < n; i++) {
            currMax = max(nums[i] + currMax, nums[i]);
            maxSum = max(maxSum, currMax);
            currMin = min(nums[i] + currMin, nums[i]);
            minSum = min(minSum, currMin);

            totalSum += nums[i];
        }
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};

// Just one to pay attention:
// If all numbers are negative, maxSum = max(A) and minSum = sum(A).
// In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
// According to the deacription, We need to return the max(A), instead of sum of am empty subarray.
// So we return the maxSum to handle this corner case.
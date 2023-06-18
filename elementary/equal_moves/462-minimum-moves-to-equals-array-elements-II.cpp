#include <bits/stdc++.h>
using namespace std;

// Brute force: equalized element k is in range of [minVal, maxVal]
// time O(n * diff), space O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        long res = LONG_MAX;

        for (int i = minVal; i <= maxVal; i++) {
            long sum = 0;
            for (auto num : nums) {
                sum += abs(i - num);
            }
            res = min(sum, res);
        }
        return (int)res;
    }
};

// Better brute force 1: proved final equalized element k in array must be one of
// the existing elements in current array.
// time O(n^2), space O(1)
class Solution2 {
public:
    int minMoves2(vector<int>& nums) {
        long res = LONG_MAX;
        for (auto n : nums) {
            long sum = 0;
            for (auto num : nums) {
                sum += abs(num - n);
            }
            res = min(res, sum);
        }
        return (int)res;
    }
};

// Better brute force 2: count moves from the final equalized array (n, k),
// https://www.cnblogs.com/grandyang/p/6089060.html
// time O(nlogn), space O(1)
class Solution3 {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long res = LONG_MAX, currSum = 0;
        long sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long k = nums[i];
            currSum += k;
            long moves = 2 * k * (i + 1) - n * k + sum - 2 * currSum;
            res = min(res, moves);
        }
        return (int)res;
    }
};

// Median: proved final equalized elements k must be the median
// time O(nlogn), space O(1)
class Solution4 {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // Alternatively, stl nth_element() find median in O(n)
        // int mid = nums.size() / 2;
        // nth_element(nums.begin(), nums.begin() + mid, nums.end());

        int res = 0, mid = nums[nums.size() / 2];
        for (auto num : nums) {
            res += abs(num - mid);
        }
        return res;
    }
};

// Median 2: same as Median 1
class Solution5 {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            res += nums[j] - nums[i];
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ====== method 1: time O(n), space O(1) ======
    int missingNumber_1(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        return n * (n + 1) / 2 - sum;
    }

    // ===== method 2: time O(n), space O(n) =====
    int missingNumber_2(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        for (int i = 0; i <= n; ++i) {
            if (!set.count(i)) return i;
        }
        return -1;
    }

    // ===== method 3: time O(nlogn) space O(1) =====
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    // ===== method 4: time O(n), space O(1) =====
    int missingNumber_4(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            res ^= (i ^ nums[i]);
        }
        return res;
    }

    // For a normal nums with [0...n], index ^ nums[index] should be 0;
    // Then we introduce the n=nums.size() when XOR for alignments.
    // e.g. [0, 1, 2, 4, 5], n=5
    //    5 ^ (0^0) ^ (1^1) ^ (2^2) ^ (3^4) ^ (4^5)
    // => (0^0) ^ (1^1) ^ (2^2) ^ 3 ^ (4^4) ^ (5^5) => 3
};
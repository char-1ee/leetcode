#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // unordered set. time O(n) space O(n).
    int firstMissingPositive_solution1(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res; // that missing positive
        int n = nums.size();
        for (res = 1; res <= n; res++) {
            if (!s.count(res)) {
                return res;
            }
        }
        return res;
    }

    // index as hash key (negative marking). time O(n), space O(1).
    // negative marking is to utilize the signs of whole array as hashtable (extra space).
    int firstMissingPositive_solution2(vector<int>& nums) {
        int n = nums.size();
        int is_1_present = false;

        // check if 1 is present in array
        for (int num : nums) {
            if (num == 1) {
                is_1_present = true;
                break;
            }
        }
        if (!is_1_present) return 1;

        // replace non-positives and numbers larger nums.len than  by 1s
        for (int& num : nums) {
            if (num <= 0 || num > n) num = 1;
        }

        // Change sign of a-th element if meet number a.
        // Use index 0 to save infomation of presence of number n since index n is not available.
        for (int num : nums) {
            int idx = abs(num);
            if (idx == n) {
                if (nums[0] > 0) nums[0] *= -1;
            } else {
                if (nums[idx] > 0) nums[idx] *= -1;
            }
        }

        // Find the missing number (start with 1 since index 0 is used)
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }

        if (nums[0] > 0) return n;

        return n + 1;
    }

    // Index as hash key. But in-place opreations.
    // 1 -> nums[0]
    // 2 -> nums[1]
    // i -> nums[i - 1]
    // nums[i] -> nums[nums[i] - 1]
    int firstMissingPositive_solution3(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // if not using loop, then indexes before current i cannot be covered.
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

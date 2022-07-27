#include <bits/stdc++.h>

using namespace std;

// Negative marking. time O(n), space O(1)
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
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

// Array as hashmap. time O(n) space O(1).
// Utilize index 0 because element ranging from [1, n], then always map
// the number at index 0 to its equivalent index until meeting repeated number.
// Time is O(n) since each number needs to be swapped at most once before placed
// to desired position. No addition space used but modified array.
class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};

// Binary search. time O(nlogn) space O(1)
class Solution3 {
public:
    int findDuplicate(vector<int>& nums) {
        // lambda to count elements in vector less or equal than mid
        auto count = [&](int mid) {
            int count = 0;
            for (int& num : nums) {
                if (num <= mid) count++;
            }
            return count;
        };

        int dup = -1;
        int lo = 1, hi = nums.size() - 1;
        while (lo <= hi) { // O(logn)
            int mid = lo + (hi - lo) / 2;
            if (count(mid) > mid) { // O(n)
                dup = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return dup;
    }
};
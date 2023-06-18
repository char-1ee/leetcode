#include <bits/stdc++.h>
using namespace std;

// ===== Solution 1 =====
// Randomization + Binary search + Partition. time O(n)
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int n = nums.size();
        int mid = n / 2;
        int start = 0, end = n - 1;
        int index = partition(nums, start, end); // O(n)

        while (index != mid) { // O(logn)
            if (index > mid) {
                end = index - 1;
                index = partition(nums, start, end);
            } else {
                start = index + 1;
                index = partition(nums, start, end);
            }
        }
        return nums[index];
    }

    int partition(vector<int>& nums, int start, int end) {
        int index = rand() % (end - start + 1) + start;
        swap(nums[start], nums[index]);

        int pivot = nums[start];
        int i = start, j = end + 1;

        while (true) {
            while (nums[++i] < pivot) {
                if (i >= end) break;
            }
            while (nums[--j] > pivot) {
                if (j <= start) break;
            }
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }

        swap(nums[start], nums[j]);

        return j;
    }
};

// ===== Solution 2 =====
// Sorting + median. time O(nlogn)
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// ===== Solution 3 =====
// Boyer-Moore voting algorithm. time O(n)
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int cnt = 0;
        int res = numeric_limits<int>::min();
        for (int num : nums) {
            if (cnt == 0) res = num;
            if (res != num) cnt--;
            else cnt++;
        }
        return res;
    }
};

// ===== Solution 2 =====
// Divide and Conquer. time O(nlogn)
class Solution4 {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElementCore(nums, 0, nums.size() - 1);
    }
    
    int majorityElementCore(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return nums[lo];
        
        int mid = lo + (hi - lo) / 2;
        int left = majorityElementCore(nums, lo, mid); // left subarray majority element
        int right = majorityElementCore(nums, mid + 1, hi); // right subarray majority element

        if (left == right) {
            return left;
        }
        
        int left_count = countInRange(nums, left, lo, hi);
        int right_count = countInRange(nums, right, lo, hi);
        
        return left_count > right_count ? left : right;
    }
    
    int countInRange(vector<int>& nums, int target, int lo, int hi) {
        int cnt = 0;
        for (int i = lo; i <= hi; ++i) {
            if (nums[i] == target) cnt++;
        }
        return cnt;
    }
};
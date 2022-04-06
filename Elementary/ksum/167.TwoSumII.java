package elementary.ksum;

class Solution {
    /** Binary search: O(nlogn) */
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            int num = target - nums[i];
            int left = i + 1, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == num) {
                    return new int[] { i + 1, mid + 1 };
                } else if (nums[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return null;
    }

    /** Two pointers: O(n) */
    public int[] twoSum2(int[] nums, int target) {
        int i = 0, j = nums.length - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target)
                break;
            else if (sum < target)
                i++;
            else
                j--;
        }
        return new int[] { i + 1, j + 1 };
    }
}
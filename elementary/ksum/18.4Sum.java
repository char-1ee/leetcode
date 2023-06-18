package elementary.ksum;

import java.util.*;

class Solution {
    /**
     * General idea: 4sum -> 3sum -> 2sum -> two pointers
     * Time complexity: O(n^3), Space: O(n)
     * For kSum problem: time is O(n^(k-1))
     */
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        if (n < 4)
            return res;
        for (int i = 0; i < n - 3; i++) { // 4Sum: O(n)
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) { // threeSum: O(n)
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = n - 1;
                while (left < right) { // twoSum: O(n)
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum == target) {
                        res.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
}

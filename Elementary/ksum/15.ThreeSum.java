package elementary.ksum;

import java.util.*;

/** general idea: turn 3-sum into 2-sum (hashset or two pointers) */
class Solution {
    /** 
     * Sort + two pointers 
     * Time: O(n^2)
     */
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        if (nums.length < 3 || nums[0] > 0 || nums[n - 1] < 0)
            return res;

        for (int k = 0; k < n - 2; k++) {
            // If the current value is greater than zero, break from the loop. 
            if (nums[k] > 0) break;
            // If the current value is the same as the one before, skip it.
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            
            // do a twoSumII operation
            int sum = 0 - nums[k];
            int i = k + 1, j = n - 1;
            while (i < j) {
                if (nums[i] + nums[j] == sum) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    while (i < j && nums[i] == nums[i + 1])
                        i++;
                    while (i < j && nums[j] == nums[j - 1])
                        j--;
                    i++;
                    j--;
                } else if (nums[i] + nums[j] < sum)
                    i++;
                else
                    j--;
            }
        }
        return res;
    }

    /**
     * Sort + Hashset
     * time: O(n^2)
     */
    public List<List<Integer>> threeSum2(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        if (n < 3 || nums[0] > 0 || nums[n-1] < 0)
            return res;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            HashSet<Integer> set = new HashSet<>();
            for (int j = i + 1; j < n; j++) {
                int target = 0 - nums[i] - nums[j];
                if (set.contains(target)) {
                    res.add(Arrays.asList(nums[i], nums[j], target));
                    while (j + 1 < n && nums[j] == nums[j+1])
                        j++;
                }
                set.add(nums[j]);
            }
        }
        return res;
    }

    /**
     * No-sort solution: https://leetcode.com/problems/3sum/solution/
     */
}

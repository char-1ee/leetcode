package elementary.ksum;

import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int diff = 13001, n = nums.length;
        Arrays.sort(nums);
        for (int k = 0; k < n - 2; k++) {
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            int i = k + 1, j = n - 1;
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (Math.abs(target - sum) < Math.abs(diff)) {
                    diff = target - sum;
                }
                if (sum < target)
                    i++;
                else // sum >= target
                    j--;
            }
        }
        return target - diff;
    }
}

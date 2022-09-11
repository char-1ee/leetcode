package resursion_dp;

import java.util.Arrays;

class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target+1];
        // when sum is 0, there can be one way of combination
        dp[0] = 1; 
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.length; j++) {
                int x = nums[j];
                if (i >= x) {
                    dp[i] += dp[i-x];
                }
            }
        }
        return dp[target];
    }

    /** Optimized dp */
    public int combinationSum4Op(int[] nums, int target) {
        int[] dp = new int[target+1];
        dp[0] = 1;
        Arrays.sort(nums); // optimization 
        for (int i = 1; i <= target; i++) {
            for (int x : nums) {
                // when encounter a threshold, jump out
                if (i < x) break;
                dp[i] += dp[i-x];
            }
        }
        return dp[target];
    }
}
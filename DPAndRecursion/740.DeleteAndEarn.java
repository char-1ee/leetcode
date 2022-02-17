package DPAndRecursion;

import java.util.Arrays;

class Solution {
    /** In-place dp */
    public int deleteAndEarn(int[] nums) {
        Arrays.sort(nums);
        int[] counts = new int[10001];
        for (int num : nums)
            counts[num] += num; // sort by buckets
        for (int i = 2; i < 10001; i++) {
            counts[i] = Math.max(counts[i - 1], counts[i - 2] + counts[i]);
        }
        return counts[10000]; // return to last position of counts[]
    }

    /**
     * 
     * https://leetcode.com/problems/delete-and-earn/discuss/109895/JavaC%2B%2B-Clean-Code-with-Explanation
     */
    public int deleteAndEarn1(int[] nums) {
        int[] dp = new int[10001];
        for (int num : nums)
            dp[num] += num;
        
        // previous take and skip for take_i and skip_i
        int take = 0, skip = 0;
        for (int i = 0; i < 10001; i++) {
            // skip_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you skip the ith bucket.
            // take_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you take the ith bucket.
            int take_i = skip + dp[i];
            int skip_i = Math.max(skip, take);
            take = take_i;
            skip = skip_i;
        }
        return Math.max(take, skip);
    }
}
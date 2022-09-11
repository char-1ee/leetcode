package dp;

class Solution {
    /** Kadane's algorithm */
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int currSubarray = nums[0], maxSubarray = nums[0];
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            currSubarray = Math.max(num, num + currSubarray);
            maxSubarray = Math.max(currSubarray, maxSubarray);
        }
        return maxSubarray;
    }

    /**
     * A variation is:
     * If array contains negative while allow return subarray with length 0
     */
    public int maxSubArray2(int[] nums) {
        int n = nums.length;
        int currSubarray = 0, maxSubarray = 0; // initialize as 0
        for (int i = 0; i < n; i++) { // start from 0
            int num = nums[i];
            currSubarray = Math.max(0, num + currSubarray); // compare with 0
            maxSubarray = Math.max(currSubarray, maxSubarray);
        }
        return maxSubarray;
    }

    /** Prefix sum */
    public int maxSubArray3(int[] nums) {
        int minSum = 0;        
        int maxSum = nums[0];
        
        int runningSum = 0;

        for (int num: nums) {
            runningSum += num;
            maxSum = Math.max(maxSum, runningSum - minSum);
            minSum = Math.min(runningSum, minSum);
        }
        return maxSum;
    }
}
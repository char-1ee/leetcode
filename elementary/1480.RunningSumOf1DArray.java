package Elementary;

class Solution {
    /** Forward In-place */
    public int[] runningSum1(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }

    /** Brute-force */
    public int[] runningSum2(int[] nums) {
        int[] sumSet = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j <= i; j++) {
                sumSet[i] += nums[j];
            }
        }
        return sumSet;
    }

    /** Backward In-place */
    public int[] runningSum3(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            nums[i + 1] += nums[i];
        }
        return nums;
    }
}

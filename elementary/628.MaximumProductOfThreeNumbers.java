package elementary;

import java.util.Arrays;

class Solution {
    public int maximumProduct(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        return Math.max(nums[n-2] * nums[n-1] * nums[n-3],
                       nums[0] * nums[1] * nums[n-1]);
    }

    public int maximumProduct2(int[] nums) {
        int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE; // min1 < min2
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE; // max1 > max2 > max2
        for (int num : nums) {
            if (num <= min1) {
                min2 = min1;
                min1 = num; 
            } else if (num <= min2) {
                min2 = num;
            } 
            if (num >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num >= max2) {
                max3 = max2;
                max2 = num;
            } else if (num >= max3) {
                max3 = num;
            }
                        
        }
        return Math.max(min1 * min2 * max1, max1 * max2 * max3);
    }
}
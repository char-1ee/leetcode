package Elementary;

import java.util.Arrays;

class Solution {
    /** Time complexity: O(n) */
    public int[] sortedSquares1(int[] nums) {
        int N = nums.length;
        int ptr1 = 0, ptr2 = N - 1; // Two pointers approach
        int[] res = new int[N];

        for (int i = N - 1; i >= 0; i--) {
            if (Math.abs(nums[ptr1]) > Math.abs(nums[ptr2])) {
                res[i] = nums[ptr1] * nums[ptr1];
                ptr1++;
            } else {
                res[i] = nums[ptr2] * nums[ptr2];
                ptr2--;
            }
        }
        return res;
    }

    /** Time complexity: O(nlogn) */
    public int[] sortedSquares2(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] = nums[i] * nums[i];
        }
        Arrays.sort(nums);
        return nums;
    }
}

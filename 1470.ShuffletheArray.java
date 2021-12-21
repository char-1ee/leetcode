class Solution {
    /** Two pointer method */
    public int[] shuffle(int[] nums, int n) {
        // involve two pointers into loop
        int pt1 = 0, pt2 = n;
        int[] res = new int[nums.length];
        for (int i = 0; i < 2 * n; i += 2) {
            res[i] = nums[pt1++];
            res[i + 1] = nums[pt2++];
        }
        return res;
    }

    /** Bitwise in-place method, time O(n) and space O(1) */
    public int[] bitwiseShuffle(int[] nums, int n) {
        int i = n - 1;
        for (int j = 2 * n - 1; j >= n; j--) {
            nums[j] <<= 10;
            nums[j] |= nums[i];
            i--;
        }

        i = 0;
        for (int j = n; j < 2 * n; j++) {
            int num1 = nums[j] & 1023;
            int num2 = nums[j] >> 10;
            nums[i] = num1;
            nums[i + 1] = num2;
            i += 2;
        }
        return nums;
    }

    /**
     * Refer to this solution: https://leetcode.com/problems/shuffle-the-array/discuss/675956/In-Place-O(n)-Time-O(1)-Space-With-Explanation-and-Analysis
     */
}

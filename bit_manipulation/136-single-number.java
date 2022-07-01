package bit_manipulation;

class Solution {
    /**
     * Bit Manipulation:
     * a ^ 0 = a;
     * a ^ a = 0;
     * a ^ b ^ a = (a ^ a) ^ b = b; OHHHHHHHHH
     */
    public int singleNumber(int[] nums) {
        int res = nums[0];
        for (int i = 1; i < nums.length; i++) {
            res ^= nums[i];
        }
        return res;
    }
}

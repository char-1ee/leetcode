package Elementary;

class Solution {
    /**
     * Mathematic simplification
     */
    public int findMaxConsecutiveOnes1(int[] nums) {
        int sum = 0, res = 0;
        for (int num : nums) {
            sum = num * (sum + num);
            res = Math.max(res, sum);
        }
        return res;
    }

    /**
     * Every array element has two status: 1 or 0
     */
    public int findMaxConsecutiveOnes2(int[] nums) {
        int res = 0;
        int cnt = 0;
        for (int num : nums) {
            cnt = (num == 0) ? 0 : cnt + 1;
            res = Math.max(res, cnt);
        }
        return res;
    }
}

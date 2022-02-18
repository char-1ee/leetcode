class Solution {
    /** Top-down */
    int n, m;
    int[] nums, muls;
    int[][] memo;
    
    public int maximumScore(int[] nums, int[] multipliers) {
        this.n = nums.length;
        this.m = multipliers.length;
        this.nums = nums;
        this.muls = multipliers;
        this.memo = new int[m][m];
        return dp(0, 0);
    }
    
    private int dp(int left, int i) {
        if (i == m) return 0;
        int right = n - 1 - (i - left);
        
        if (memo[left][i] == 0) {
            int pickLeft= nums[left] * muls[i] + dp(left + 1, i + 1);
            int pickRight = nums[right] * muls[i] + dp(left, i + 1);
            memo[left][i] = Math.max(pickLeft, pickRight);
        }
        return memo[left][i];
    }

    /** Bottom-up */
    public 
}
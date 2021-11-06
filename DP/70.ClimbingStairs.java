package DP;

class Solution {
    public int climbStairs(int n) {
        if (n <= 1) return n;
        int[] dp = new int[n+1];

        dp[0] = 0; 
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) 
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }

    /**
     * DP optimized
     */
    public int climbStairs2(int n) {
        if (n <= 1)
            return n;
        int prev1 = 1;
        int prev2 = 2;

        for (int i = 3; i <= n; i++) {
            int new_value = prev1 + prev2;
            prev1 = prev2;
            prev2 = new_value;
        }

        return prev2;
    }
}
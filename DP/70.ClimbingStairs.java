package DP;

class Solution {
    public itn climbStairs(int n) {
        if (n <= 1) return n;
        int[] dp = new int[n+1];

        dp[0] = 0; 
        dp[1] = 1;
        dp[2] = 2;

        if (int i = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }
}
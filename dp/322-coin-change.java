package dp;

class Solution {
    public int coinChange(int[] coins, int amount) {
        // dp[i] means min ways to sum i
        int[] dp = new int[amount + 1];
        dp[0] = 0;
        for (int i = 1; i < dp.length; i++) {
            dp[i] = amount + 1;
        }
        for (int i = 1; i <= amount; i++) {
            for (int x : coins) {
                if (i >= x) {
                    dp[i] = Math.min(dp[i], dp[i - x] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}
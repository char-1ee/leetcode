package DP;

class MinCostClimbingStairs {
    public int minCostClimbingStairs1(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n];      // dp[i] stands for min cost when reach (i+1)th
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i=2; i<n; i++){
            dp[i] = Math.min(dp[i-1], dp[i-2]) + cost[i];
        }
        
        return Math.min(dp[n-1], dp[n-2]);  // there is no cost[n] for top floor
    }

    public int minCostClimbingStairs2(int[] cost){
        int a = 0, b = 0;
        for (int num : cost){
            int temp = Math.min(a, b) + num;
            a = b;
            b = temp;
        }

        return Math.min(a, b);
    }
}

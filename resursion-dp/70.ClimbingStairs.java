package DPAndRecursion;

import java.util.HashMap;

class Solution {
    /** DP */
    public int climbStairs(int n) {
        if (n <= 1)
            return n;
        int[] dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }

    /** Optimized DP */
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

    /** Recursion with memoization */
    private HashMap<Integer, Integer> cathe = new HashMap<>();

    public int climbStairs3(int n) {
        if (cathe.containsKey(n))
            return cathe.get(n);
        int res;
        if (n < 4)
            return n;
        else
            res = climbStairs3(n - 1) + climbStairs3(n - 2);
        cathe.put(n, res);
        return res;
    }

}
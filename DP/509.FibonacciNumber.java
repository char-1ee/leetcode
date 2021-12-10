package DP;

class FibonacciNumber {
    public int fib(int n) {
        if (n <= 1)
            return n;

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {      // Start from i=2 to i=n (instead of i=n-1)
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];                       // return n-th element
    }
}

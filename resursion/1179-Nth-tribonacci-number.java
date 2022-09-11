class NthTribonacciNumber {

    /* DP Method 1 */
    public int tribonacci1(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }

    /* DP Method 2: Amazing */
    public int tribonacci2(int n) {
        int dp[] = { 0, 1, 1 };
        for (int i = 3; i <= n; ++i)
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        return dp[n % 3];
    }

    /**
     * https://leetcode.com/problems/n-th-tribonacci-number/discuss/345236/JavaC%2B%2BPython-Easy-and-Concise
     */
    public int tribonacci3(int n) {
        if (n < 2)
            return n;
        int a = 0, b = 1, c = 1, d;
        while (n-- > 2) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
}

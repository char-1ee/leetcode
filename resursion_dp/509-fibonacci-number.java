import java.util.HashMap;

class FibonacciNumber {

    /** DP */
    public int fibDP(int n) {
        if (n <= 1)
            return n;

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) { // Start from i=2 to i=n (instead of i=n-1)
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n]; // return n-th element
    }

    /** Recursion */
    public int fib(int n) {
        if (n < 2)
            return n;
        else
            return fib(n - 1) + fib(n - 2);
    }

    /** recursion with cathe */
    private HashMap<Integer, Integer> cathe = new HashMap<>();

    public int fibmemo(int n) {
        if (cathe.containsKey(n))
            return cathe.get(n);
        int res;
        if (n < 2)
            return n;
        else
            res = fibmemo(n - 1) + fibmemo(n - 2);
        cathe.put(n, res);
        return res;
    }
}

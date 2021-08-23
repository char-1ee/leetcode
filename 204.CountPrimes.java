import java.util.Arrays;

class Solution{
    /**
     * My primary solution by Sieve of Eratosthenes
     */
    public int countPrimes1(int n){
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        int cnt = 0;
        if ( n == 0 || n == 1) return 0;
        prime[0] = prime[1] = false;
        for (int i = 2; i <= Math.sqrt(n); i++){
             if (prime[i] == true){
                 for (int j = i * i; j < n; j += i){
                    prime[j] = false;
                 }
             }
        }
        for (int i = 0; i < n; i++ ){
            if (prime[i] == true) cnt++;
        }
        return cnt;
    }

    /**
     * Runtime Error solution
     * 
     * A problem may encounter: 499979 Runtime error
     * Related blogs: 
     * https://www.git2get.com/av/46334797.html
     * https://leetcode.com/problems/count-primes/discuss/57596/why-am-i-getting-runtime-error-for-input-being-499979-could-not-figure-out
     * https://leetcode.com/problems/count-primes/discuss/57741/runtime-error-with-last-executed-input-499979
     * 
     */
    public int countPrimesOverflow(int n) {
        boolean[] prime = new boolean[n];
        int cnt = 0;
        for (int i = 2; i < n; i++){ // range in n because we need cnt iterating to n
            if (prime[i] == false){
                cnt++;
                for (int j = i*i; j < n; j += i){
                    // since we need to iterate i to n, j = i*i (n*n) cannot avoid overflowing
                    prime[j] = true;
                }
            }
        }
        return cnt;
    }

    /**
     * Solution by Type Conversions
     */
    public int countPrimes2(int n) {
        boolean[] prime = new boolean[n];
        int cnt = 0;
        
        for (int i = 2; i < n; i++){ 
            if (prime[i] == false){
                cnt++;
                for (long j = (long) i*i; j < n; j += i){   
                    prime[(int)j] = true; 
                }
            }
        }
        return cnt;
    }

    /**
     * Solution by https://leetcode.com/problems/count-primes/discuss/57588/My-simple-Java-solution
     */
    public int countPrimes3(int n) {
        boolean[] prime = new boolean[n];
        int cnt = 0;
        
        for (int i = 2; i < n; i++){ 
            if (prime[i] == false){
                cnt++;
                for (int j = 2; i * j < n; j ++){ // A controllable loop condition
                    prime[i*j] = true; // However, an inperfect time complexity due to repeatedly check
                }
            }
        }
        return cnt;
    }

    /**
     * Solution that improves the Sieve of Eratosthenes: 
     * by https://leetcode.com/problems/count-primes/discuss/57593/12-ms-Java-solution-modified-from-the-hint-method-beats-99.95
     */
    public int countPrimes4(int n) {
        
        /**
         * if n = 2, the prime 2 is not less than n,
         * so there are no primes less than n
         */
        if (n < 3) return 0;
        
        /** 
         * Start with the assumption that half the numbers below n are
         * prime candidates, since we know that half of them are even,
         * and so _in general_ aren't prime.
         * 
         * An exception to this is 2, which is the only even prime.
         * But also 1 is an odd which isn't prime.
         * These two exceptions (a prime even and a for-sure not-prime odd)
         * cancel each other out for n > 2, so our assumption holds.
         * 
         * We'll decrement count when we find an odd which isn't prime.
         *
         * If n = 3,  c = 1.
         * If n = 5,  c = 2.
         * If n = 10, c = 5.
         */
        int c = n / 2;
        
        /**
         * Java initializes boolean arrays to {false}.
         * In this method, we'll use truth to mark _composite_ numbers.
         * 
         * This is the opposite of most Sieve of Eratosthenes methods,
         * which use truth to mark _prime_ numbers.
         * 
         * We will _NOT_ mark evens as composite, even though they are.
         * This is because `c` is current after each `i` iteration below.
         */
        boolean[] s = new boolean[n];
        
        /**
         * Starting with an odd prime-candidate above 2, increment by two
         * to skip evens (which we know are not prime candidates).
         */
        for (int i = 3; i * i < n; i += 2) {
            if (s[i]) {
                // c has already been decremented for this composite odd
                continue;
            }
            
            /** 
             * For each prime i, iterate through the odd composites
             * we know we can form from i, and mark them as composite
             * if not already marked.
             * 
             * We know that i * i is composite.
             * We also know that i * i + i is composite, since they share
             * a common factor of i.
             * Thus, we also know that i * i + a*i is composite for all real a,
             * since they share a common factor of i.
             * 
             * Note, though, that i * i + i _must_ be composite for an
             * independent reason: it must be even.
             * (all i are odd, thus all i*i are odd,
             * thus all (odd + odd) are even).
             * 
             * Recall that, by initializing c to n/2, we already accounted for
             * all of the evens less than n being composite, and so marking
             * i * i + (odd)*i as composite is needless bookkeeping.
             * 
             * So, we can skip checking i * i + a*i for all odd a,
             * and just increment j by even multiples of i,
             * since all (odd + even) are odd.
             */
            for (int j = i * i; j < n; j += 2 * i) {
                if (!s[j]) {
                    c--;
                    s[j] = true;
                    }
                }
            }
        return c;
    }
}


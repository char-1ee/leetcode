package mathematic;

import java.util.ArrayList;
import java.util.List;

class Solution {

    private final static int HALF_INT_MIN = -1073741824;

    public int divide(int dividend, int divisor) {
        // edge case
        if (dividend == Integer.MIN_VALUE && divisor == -1)
            return Integer.MAX_VALUE;
        // noticed that for division3, below case is necessary
        if (dividend == Integer.MIN_VALUE && divisor == 1)
            return Integer.MIN_VALUE;

        // change any positive to negative to avoid overflow: -2^31
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        dividend = (dividend < 0) ? dividend : -dividend;
        divisor = (divisor < 0) ? divisor : -divisor;
        
        // three cases
        if (dividend > divisor) return 0;
        else if (dividend == divisor) return sign*1;
        else // dividend < divisor
        return sign * division(dividend, divisor);
    }
    
    // repeated substraction, O(n), TLE
    public int division(int a, int b) { // a, b < 0
        int cnt = 0;
        while (a <= b) {
            a -= b;
            cnt++;
        }
        return cnt;
    }

    // repeated exponential searches, O(logn*logn)
    public int division2(int a, int b) {
        int cnt = 0;
        while (a <= b) {
            int power = 1;
            int copy = b; // get a copy of divisor
            // in case copy + copy <= Integer.MIN_VALUE
            while (copy >= HALF_INT_MIN && copy + copy >= a) {
                copy += copy;
                power += power;
            }
            a -= copy;
            cnt += power;
        }
        return cnt;
    }

    // repeated exponential search with memorization, O(logn)
    public int division3(int a, int b) {
        List<Integer> doubles = new ArrayList<>();
        while (a <= b) {
            doubles.add(b);
            if (b < HALF_INT_MIN)
                break;
            b += b;
        }
        int cnt = 0;
        for (int i = doubles.size() - 1; i >= 0; i--) {
            if (doubles.get(i) >= a) {
                cnt += Math.pow(2, i);
                a -= doubles.get(i);
            }
        }
        return cnt;
    }
}
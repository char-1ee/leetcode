class Solution {
public:
    /** iterative 1 */
    double myPow1(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n < 0 ? 1.0 / res : res;
    }

    /** iterative 2 */
    double myPow2(double x, int n) {
        double res = 1.0;
        long long nn = abs(n); // n = -2^31
        while (nn) {
            if (nn % 2 == 0) { 
                x *= x;
                nn /= 2;
            } else {
                res *= x;
                nn--;
            }
        }
        return n < 0 ? 1.0 / res : res; 
    }

    /** recursive */
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            x = 1.0 / x;
            return (n % 2 == 0) ? myPow(x * x, -(n/2)) : x * myPow(x * x, -(n/2));
        }
        return (n % 2 == 0) ? myPow(x*x, n / 2) : x * myPow(x*x, n / 2);
    }
};
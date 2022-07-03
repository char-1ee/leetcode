class Solution {
public:
    // Method 1: iteration
    // time O(logn), space O(1)
    bool isPowerOfThree_1(int n) {
        if (n < 3) return n == 1; 

        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }

    // Method 2: logarithms
    // space O(1)
    bool isPowerOfThree_2(int n) {
        auto num = log10(n) / log10(3);
        return n > 0 && (num - int(num) == 0);
    }

    // Method 3: integer limitation
    // time O(1), space O(1)
    bool isPowerOfThree_3(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

// Type signed int is 4 btyes, range from (2^31 - 1) to (-2^31). The INT_MAX is 2147483647.
// Then in that range, maximum value of power of 3 is 1162261467, which is
// 3 ^ log3(INT_MAX) = 3 ^ 19.56 = 3 ^ 19 = 1162261467
// Thus, if given n is power of 3, n is a factor of 1162261467.
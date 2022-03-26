class Solution {
public:
    // 0 <= n <= 10^9

    int bitwiseComplement1(int n) {
        if (n == 0) return 1;
        unsigned int mask = ~0;
        while (mask & n) mask <<= 1;
        return ~mask & ~n;
    }

    int bitwiseComplement2(int n) {
        int m = 1;
        while (m < n) m = 2* m + 1;
        return m ^ n;   // m - n
    }
}
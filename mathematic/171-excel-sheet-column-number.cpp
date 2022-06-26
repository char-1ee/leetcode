#include <bits/stdc++.h>

class Solution {
public:
    // ===== time O(n), space O(1) =====
    int titleToNumber(string columnTitle) {
        int res = 0;
        int n = columnTitle.length();
        for (int i = 0; i < n; ++i) {
            int digit = columnTitle[i] - 'A' + 1;
            res = res * 26 + digit ;
        }
        return res;
    }

    // ===== overflow for caes "FXSHRXW" =====
    int titleToNumber_overflow(string columnTitle) {
        int exp = 1, res = 0;
        int n = columnTitle.length();
        for (int i = n - 1; i >= 0; --i) {
            int digit = columnTitle[i] - 'A' + 1;
            res += digit * exp;
            exp *= 26;
        }
        return res;
    }
};

// This is a problem of convert base 10 to base 26.
// The accepted solution scans the string from left to right, 
// while the overflow solution scans from right to left.
// Thus, when calculating bases, do operating on accumulated sum itself, 
// rather than using helper variables like `exp`, which causes overflow.
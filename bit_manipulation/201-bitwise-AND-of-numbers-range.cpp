#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd1(int left, int right) {
        int i = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            i++;
        }
        return left << i;
    }

    int rangeBitwiseAnd2(int m, int n) {
        unsigned int mask = UINT_MAX;
        while ((m & mask) != (n & mask)) {
            mask <<= 1;
        }
        return m & mask;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(long long d1, long long d2, long long cnt1, long long cnt2,
               long long x) {
        long long _lcm = lcm(d1, d2);
        long long A = x / d2 - x / _lcm;
        long long B = x / d1 - x / _lcm;
        long long AuB = x / d1 + x / d2 - x / _lcm;
        return x - AuB >= max(0LL, cnt1 - A) + max(0LL, cnt2 - B);
    }

    int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
        long long lo = 1, hi = INT_MAX;
        while (lo + 1 < hi) {
            long long mid = (hi + lo) >> 1;
            if (check(d1, d2, cnt1, cnt2, mid))
                hi = mid;
            else
                lo = mid;
        }
        return hi;
    }
};
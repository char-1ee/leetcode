#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numWays(string s) {
        long long n = s.size();
        int mod = 1e9 + 7;
        if (n == 3) return 1;

        int total = 0;
        for (auto c : s) {
            if (c == '1') total++;
        }

        if (total == 0) return (int)((n - 1) * (n - 2) / 2 % mod);
        if (total % 3 != 0) return 0;

        total /= 3;
        long long curr = 0, x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') curr++;
            if (curr == total) x++;
            if (curr == 2 * total) y++;
        }
        return (int)((x * y) % mod);
    }
};
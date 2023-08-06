#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int accountBalanceAfterPurchase(int p) {
        if (p == 0) return 100;
        int x = 0;
        while (x < p) {
            x += 10;
        }
        if ((x - p) > (p - x + 10)) {
            x -= 10;
        }
        return 100 - x;
    }
};
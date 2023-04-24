#include <bits/stdc++.h>

class Solution {
    int sumOfMultiple(int n, int k) { return k * (n / k) * (n / k + 1) / 2; }

   public:
    int sumOfMultiples(int n) {
        return sumOfMultiple(n, 3) + sumOfMultiple(n, 5) + sumOfMultiple(n, 7) -
               sumOfMultiple(n, 15) - sumOfMultiple(n, 21) -
               sumOfMultiple(n, 35) + sumOfMultiple(n, 105);
    }
};
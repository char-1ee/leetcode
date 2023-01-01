#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countDigits(int num) {
        int res = 0, n = num;
        while (num) {
            int digit = num % 10;
            if (n % digit == 0) res++;
            num /= 10;
        }
        return res;
    }

    int countDigits2(int num) {
        int res = 0;
        for (auto x : to_string(num)) {
            if (num % (x - '0') == 0) res++;
        }
        return res;
    }
};
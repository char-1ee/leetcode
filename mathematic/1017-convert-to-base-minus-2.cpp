#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string baseNeg2_solution1(int n) {
        string res = "";
        while (n) {
            string digit = to_string(n & 0x1);
            res = digit + res;
            n = -(n >> 1); // base -2: right shift i bit and then minus
        }
        return res == "" ? "0" : res;
    }

    // Geek4Geeks: https://www.geeksforgeeks.org/convert-number-negative-base-representation/
    string baseNeg2_solution2(int n) {
        string res = "";
        while (n) {
            int rem = n % (-2);
            n /= (-2);
            if (rem < 0) {
                rem += 2;
                n += 1;
            }
            res = to_string(rem) + res;
        }
        return max(string("0"), res);
    }
};
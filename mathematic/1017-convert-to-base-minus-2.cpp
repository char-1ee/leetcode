#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        string res = "";
        while (n) {
            string digit = to_string(n & 0x1);
            res = digit + res;
            n = -(n >> 1); // base -2: right shift i bit and then minus
        }
        return res == "" ? "0" : res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        bool is_negative = (numerator < 0) ^ (denominator < 0);

        // avoid abs(INT_MIN)
        long long a = abs((long long)numerator);
        long long b = abs((long long)denominator);
        long long qout = a / b;
        long long rem = a % b;

        // step 1: integer part
        string res = "";
        if (is_negative) {
            res += "-";
        }
        res += to_string(qout);
        if (rem == 0) return res;
        res += ".";

        // step 2: fraction part
        string s = ""; // s: string for fraction part
        int pos = 0; // position in string s
        unordered_map<long long, int> m;

        while (rem != 0) {
            // if encounter repeating part
            if (m.count(rem)) {
                s.insert(m[rem], "(");
                s += ")";
                break;
            }
            // add next digit
            m[rem] = pos;
            long long next_digit = (rem * 10) / b;
            s += to_string(next_digit);

            // update
            rem = (rem * 10) % b;
            pos++;
        }
        return res + s;
    }
};
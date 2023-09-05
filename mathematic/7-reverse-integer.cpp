#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (res > INT_MAX / 10 || res < INT_MIN / 10) {
                return 0;
            }
            res = x % 10 + res * 10;
            x /= 10;
        }
        return res;
    }
};

class Solution_2 {
public:
    int reverse(int x) {
        int f = x < 0 ? -1 : 1;
        string s = to_string(abs(x));
        int n = s.length();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        long res = f * stol(s);
        if (res > INT_MAX || res < INT_MIN) return 0;
        return (int)res;
    }
};
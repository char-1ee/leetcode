#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string breakPalindrome(string s) {
        int n = s.length(), i;
        if (n == 1) return "";

        for (i = 0; i < n / 2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
        }
        s[n - 1] = 'b';
        return s;
    }
};
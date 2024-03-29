#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /** Two pointers towards each other */
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0, j = s.size() - 1;
        while (i <= j)
            if (s[i++] != s[j--]) return false;
        return true;
    }

    /** Built-in reverse */
    bool isPalindrome2(int x) {
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return to_string(x) == s;
    }

    /** Numeric operations */
    bool isPalindrome3(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int rev = 0;
        while (x > rev) {
            rev = x % 10 + rev * 10;
            x /= 10;
        }
        return x == rev || x == (rev / 10);
    }
};
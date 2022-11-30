#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (s.length() < numRows || numRows == 1) return s;

        int i = 0, n = s.length();
        vector<string> rows(numRows);
        while (i < n) {
            for (int j = 0; j < numRows && i < n; j++, i++) rows[j] += s[i];
            for (int j = numRows - 2; j > 0 && i < n; j--, i++) rows[j] += s[i];
        }

        string res = "";
        for (auto ss : rows) {
            res += ss;
        }
        return res;
    }
};
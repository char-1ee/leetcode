#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        int n = s.length(), i = 0, j = 0, last = 0;
        reverse(s.begin(), s.end());
        while (j < n) {
            while (j < n && s[j] == ' ') j++;
            int start = i;
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
                last = i;
            }
            reverse(s.begin() + start, s.begin() + last);
            s[i++] = ' ';
        }
        s.resize(last);
        return s;
    }
};
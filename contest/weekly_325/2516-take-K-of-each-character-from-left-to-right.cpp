#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int> cnts(3, 0);  // abc
        for (auto c : s) {
            cnts[c - 'a']++;
        }

        if (cnts[0] < k || cnts[1] < k || cnts[2] < k) return -1;

        int left = 0, right = 0, len = 0, res = 0;  // length of window
        while (right < n) {
            char c = s[right];
            right++, len++;
            cnts[c - 'a']--;
            while (cnts[c - 'a'] < k) {
                char t = s[left];
                left++, len--;
                cnts[t - 'a']++;
            }
            res = max(res, len);
        }
        return n - res;
    }
};
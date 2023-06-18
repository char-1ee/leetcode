#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int compress(vector<char> &s) {
        int n = s.size(), idx = 0;  // record the length of modified array
        if (n == 1) return 1;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && s[i] == s[j]) j++;
            s[idx++] = s[i];
            if (j == i + 1) continue;  // only one char
            string cnt = to_string(j - i);
            for (auto l : cnt) {
                s[idx++] = l;
            }
        }
        return idx;
    }
};
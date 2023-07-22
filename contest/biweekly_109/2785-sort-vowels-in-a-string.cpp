#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    inline int isVowel(char ch) { return (0x208222 >> (ch & 0x1f)) & 1; }

    string sortVowels(string s) {
        int n = s.length();
        vector<char> v;
        vector<int> index;

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                v.push_back(s[i]);
                index.push_back(i);
            }
        }

        sort(v.begin(), v.end());
        int m = v.size();
        for (int i = 0; i < m; i++) {
            int idx = index[i];
            char c = v[i];
            s[idx] = c;
        }
        return s;
    }
};
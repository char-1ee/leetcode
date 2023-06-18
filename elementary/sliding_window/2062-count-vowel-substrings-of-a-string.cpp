#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countVowelSubstrings(string word) {
        return atMost(word, 5) - atMost(word, 4);
    }

    inline bool check(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int atMost(string &word, int cnt) {
        int n = word.length(), res = 0;
        unordered_map<char, int> m;

        int l = 0, r = 0;
        while (r < n) {
            char c = word[r];
            r++;

            if (!check(c)) {
                m.clear();
                l = r;
                continue;
            }

            m[c]++;
            while (m.size() > cnt) {
                char t = word[l];
                l++;
                m[t]--;
                if (m[t] == 0) m.erase(t);
            }
            res += r - l + 1;
        }
        return res;
    }
};
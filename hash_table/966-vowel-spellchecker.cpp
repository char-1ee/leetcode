#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    inline bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    inline void toLower(string &s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }

    inline void replaceVowel(string &s) {
        for (auto &c : s) {
            if (isVowel(c)) c = '_';
        }
    }

    vector<string> spellchecker(vector<string> &wordlist,
                                vector<string> &queries) {
        vector<string> res;
        unordered_set<string> st;
        unordered_map<string, string> m1, m2;

        for (auto word : wordlist) {
            st.insert(word);
            string s = word;
            toLower(word);
            if (!m1.count(word)) m1[word] = s;
            replaceVowel(word);
            if (!m2.count(word)) m2[word] = s;
        }

        for (auto &q : queries) {
            if (st.count(q)) {
                res.push_back(q);
                continue;
            }

            toLower(q);
            if (m1.count(q)) {
                res.push_back(m1[q]);
                continue;
            }

            replaceVowel(q);
            if (m2.count(q)) {
                res.push_back(m2[q]);
                continue;
            }
            res.push_back("");
        }

        return res;
    }
};
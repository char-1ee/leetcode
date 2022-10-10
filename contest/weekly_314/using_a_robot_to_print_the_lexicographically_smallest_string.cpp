#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        string res, t; // stack
        vector<int> pos(26, -1); // last position in s for a character
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'] = i;
        }

        // i for curr min character
        // k for curr s index
        for (int i = 0, k = 0; i < 26 && k < s.size(); i++) {
            char c = i + 'a';

            // mono stack greedy operation
            while (t.size() && t.back() <= c) {
                res += t.back();
                t.pop_back();
            }

            // extract remaining char in s which are smaller then c
            while (k <= pos[i]) {
                if (s[k] == c)
                    res += c;
                else
                    t += s[k];
                k++;
            }
        }

        reverse(t.begin(), t.end());
        return res + t;
    }
};
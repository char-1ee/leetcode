#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> res;
        int n = q[0].length();

        for (auto& s1 : q) {
            for (auto& s2 : d) {
                if (edit(s1, s2, n)) {
                    res.emplace_back(s1);
                    break;
                }
            }
        }
        return res;
    }

    bool edit(string& s1, string& s2, int n) {
        int k = 2;
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) continue;
            if (k-- < 0) return false;
        }
        return k < 0 ? false : true;
    }
};
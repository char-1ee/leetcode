#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isAcronym(vector<string> &words, string s) {
        string t = "";
        for (auto word : words) {
            t += word[0];
        }
        return t == s;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string diff(string s) {
        int n = s.length();
        string res = "";
        for (int i = 0; i < n - 1; i++) {
            res += s[i + 1] - s[i];
        }
        return res;
    }

    string oddString(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> map;
        for (auto& w : words) {
            map[diff(w)]++;
        }

        for (auto& w : words) {
            if (map[diff(w)] == 1) return w;
        }
        return "";
    }
};

// When need to store a vector<int> as key in hash map:
// 1. Using map instead of unordered_map. Because vector is not hashable in
// default, only RB tree can store vector as key. While for unordered_map, whose internal is hash
// table, you need to write a custom hash function for vector.
// 2. Convert vector into string. Then can use unordered_map.
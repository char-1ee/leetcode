#include <bits/stdc++.h>

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.length() == 1) {
            return 0;
        }
        
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); ++i) {
            map[s[i]]++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
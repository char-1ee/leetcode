#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLastWord_01(string s) {
        int left = 0, right = s.size() - 1;
        int res = 0;
        
        while (s[left] == ' ')  left++;
        while (s[right] == ' ') right--;
        
        for (int i = left; i <= right; ++i) {
            if (s[i] == ' ') res = 0;
            else ++res;
        }
        
        return res;
    }

    int lengthOfLastWord_02(string s) {
        int res = 0;
        int right = s.size() - 1;
        
        while (right >= 0 && s[right] == ' ') --right;
        while (right >= 0 && s[right] != ' ') {
            ++res;
            --right;
        }
        return res;
    }
};
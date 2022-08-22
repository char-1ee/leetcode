#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stack;
        vector<int> occurence(26, 0);
        vector<bool> existence(26, false);
        int length = s.length();
        
        for (int i = 0; i < length; ++i) {
            occurence[s[i] - 'a'] = i;
        }
        for (int i = 0; i < length; ++i) {
            if (existence[s[i] - 'a']) continue;
            while (!stack.empty() && s[i] < stack.top() && occurence[stack.top() - 'a'] > i) {
                existence[stack.top() - 'a'] = false;
                stack.pop();
            }
            existence[s[i] - 'a'] = true;
            stack.push(s[i]);
        }
        
        string res = "";
        while (!stack.empty()) {
            res = stack.top() + res;
            stack.pop();
        }
        return res;
    }
};
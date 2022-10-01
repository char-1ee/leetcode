#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int n = path.length();

        for (int i = 0; i < n;) {
            while (i < n && path[i] == '/') i++;
            if (i == n) break;
            int start = i;

            while (i < n && path[i] != '/') i++;
            int end = i - 1;

            string s = path.substr(start, end - start + 1);

            if (s == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (s != ".") {
                stack.push_back(s);
            }
        }

        if (stack.empty()) return "/";
        
        string res = "";
        for (auto s : stack) {
            res += "/" + s;
        }
        return res;
    }
};
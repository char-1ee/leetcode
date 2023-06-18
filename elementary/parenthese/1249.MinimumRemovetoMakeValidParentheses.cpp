#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // two pointer, two pass
    string minRemoveToMakeValid(string s) {
        int left = 0;   // left: how many open '(' from left to curr index
        int right = 0;  // right:  how many open ')' left in right of curr index
        string res;
        for (char c : s) {
            if (c == ')') right++;
        }
        for (char c : s) {
            if (c == '(') {
                // there is no need to add curr '('
                if (left == right) continue;
                // else add count of left bracket
                left++;
            } else if (c == ')') {
                // right: count of ')' to the right of current index
                right--;
                // there is no '(' so far, no need to add this ')'
                if (left == 0) continue;
                left--;
            }
            res += c;
        }
        return res;
    }
};

// mark all to-be-remove brackets in string as '*'
class Solution2 {
   public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        stack<int> st;  // only contains '(' and ')'

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty())
                    s[i] = '*';
                else
                    st.pop();
            }
        }

        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }

        for (auto c : s) {
            if (c != '*') res += c;
        }

        return res;
    }
};
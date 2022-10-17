#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0) return 0;

        int res = 0;
        stack<int> st{{-1}};
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else { // ')'
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int res = 0;
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') { // valid sequence is always ends with ')'
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    int t = i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0;
                    dp[i] = dp[i - 1] + 2 + t;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
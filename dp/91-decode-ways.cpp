#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1);
        dp[n] = 1;        
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i < n - 1 && isValid(s, i)) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
    
    bool isValid(string s, int i) {
        int d1 = s[i] - '0';
        int d2 = s[i + 1] - '0';
        int num = d1 * 10 + d2;
        return num <= 26 && num >= 10;
    }
};
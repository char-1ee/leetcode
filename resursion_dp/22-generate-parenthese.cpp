class Solution {
public:
    // f(n) = (f(0))f(n-1) + (f(1))f(n-2) + ... + (f(i))f(n-i-1) + ... + (f(n-1))f(0)
    // given f(0), f(1), for i in range(2..n), add f(i) to res
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        if (n == 1) return {"()"};
        vector<vector<string>> dp(n + 1); // 3D array
        dp[0] = {""};
        dp[1] = {"()"};
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (string p : dp[j]) {
                    for (string q : dp[i - j - 1]) {
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
                }
            }
        }
        return dp[n];
    }
};
#include <bits/stdc++.h>
using namespace std;

// DP: check subsequences iteratively
class Solution {
   public:
    bool check(const string &pred, const string &suc) {
        int n = suc.length(), i = 0;
        for (int j = 0; j < n; j++) {
            if (pred[i] == suc[j]) i++;
        }
        return i == pred.length();
    }

    int longestStrChain(vector<string> &words) {
        int n = words.size(), mxLen = 1;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (words[j].length() + 1 < words[i].length()) {
                    break;
                } else if (words[j].length() == words[i].length()) {
                    continue;
                } else {
                    if (check(words[j], words[i])) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        mxLen = max(dp[i], mxLen);
                    }
                }
            }
        }
        return mxLen;
    }
};

// DP: given a word, delete one character and update dp 
class Solution2 {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });

        int maxLen = 1;
        unordered_map<string, int> dp;
        for (auto word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.length(); i++) {
                string s = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(s)) {
                    dp[word] = max(dp[word], dp[s] + 1);
                }
                maxLen = max(maxLen, dp[word]);
            } 
        }
        return maxLen;
    }
};
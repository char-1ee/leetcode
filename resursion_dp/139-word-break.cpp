#include <bits/stdc++.h>
using namespace std;

// Recursion. TLE
// Time O(2^n), space O(n) - depth of recursion
class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string> words(wordDict.begin(), wordDict.end());
        return helper(s, words, 0);
    }

    bool helper(string s, set<string> words, int start) {
        if (start == s.length()) {
            return true;
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (words.count(s.substr(start, end - start))) {
                if (helper(s, words, end)) return true;
            }
        }
        return false;
    }
};

// Recursion with memoization, TLE
// Time O(n^3), space O(n)
class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string> words(wordDict.begin(), wordDict.end());
        vector<int> cache(n, -1);
        return helper(s, words, 0, cache);
    }

    bool helper(string s, set<string> words, int start, vector<int> cache) {
        if (start == s.length()) {
            return true;
        }
        if (cache[start] != -1) {
            return cache[start];
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (words.count(s.substr(start, end - start))) {
                if (helper(s, words, end, cache)) {
                    return cache[start] = true;
                }
            }
        }
        return cache[start] = false;
    }
};

// DP
// Time O(n^3) space O(n)
class Solution3 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
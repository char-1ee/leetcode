#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive 
    int strStr2(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.size(), m = needle.size();
        if (n < m) return -1;
        
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            int j = 0;
            for (; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == needle.size()) return i;
        }
        return -1;
    }

    // kmp
    int strStr(string text, string pattern) {
        int m = text.size(), n = pattern.size();
        if (!n) return 0; // if pattern is empty

        vector<int> lps = prefix_function(pattern);
        for (int i = 0, j = 0; i < m;) {
            if (text[i] == pattern[j]) { // matching
                i++; 
                j++;
            } 
            // find end of pattern, then return
            if (j == n) return i - j;

            if (i < m && text[i] != pattern[j]) {
                if (j == 0) 
                    i++;
                else 
                    j = lps[j - 1];
            }
        }
        return -1;
    }

    vector<int> prefix_function(string pattern) {
        int n = pattern.size();
        vector<int> lps(n);
        lps[0] = 0;
        for (int i = 1, j = 0; i < n;) {
            if (pattern[i] == pattern[j]) { // i and j match
                lps[i++] = ++j;
            } else if (j) { // i and j dont match, lookup j-1
                j = lps[j - 1];
            } else {    // lookup j-1, not match until j=0
                lps[i++] = 0;
            }
        }
        return lps;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /** 
     * Method 1: expand from center 
     * Time: O(N^2), Space: O(1)
     */
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int n = s.size();
        int maxLen = 0; // length of longest substring
        int start = 0;  // start index of longest substring

        for (int i = 0; i < n - 1; ++i) {
            partition(s, i, i, maxLen, start);  // odd center
            partition(s, i, i + 1, maxLen, start);  // even center
        }
        return s.substr(start, maxLen);
        
    }

    void partition(string s, int left, int right, int& maxLen, int& start) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left; 
                ++right;
        }
        if (maxLen < right - left - 1) {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }

    /** 
     * Method 2: Manacher's Algorithm
     * Time: O(N), Space: O(N)
     * Refer to:
     * - https://www.cnblogs.com/grandyang/p/4475985.html
     * - https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/
     */
    string longestPalindrome2(string s) {
        
        // Preprocess string: n -> 2*n+1
        string t = "~#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += "#";
        }

        // Proess new string 
        vector<int> p(t.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.size(); ++i) {

            // most important line
            p[i] = mx > i ? min(p[2 * id - 1], mx - i) : i;

            while (t[i + p[i]] == t[i - p[i]]) 
                ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i]) {    // update result length and position
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen) / 2, resLen - 1);
    }
};
#include <bits/stdc++.h>
using namespace std;

// Vertical scanning, O(all character)
class Solution_1 {
   public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";

        int n = strs.size(), m = strs[0].length();
        for (int i = 0; i < m; i++) {
            char c = strs[0][i];
            for (int j = 1; j < n; j++) {
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

// Alphabetical order sorting, then compare less common strings: s[0] and s[n-1]
class Solution_2 {
   public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string s = strs[0], t = strs[n - 1];
        int m = min(s.length(), t.length());
        for (int i = 0; i < m; i++) {
            if (s[i] != t[i]) {
                return s.substr(0, i);
            }
        }
        return s.length() < t.length() ? s : t;
    }
};

// Divide and conquer
class Solution_3 {
   public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        return LCP(strs, 0, strs.size() - 1);
    }

    string LCP(vector<string> &strs, int l, int r) {
        if (l == r) return strs[l];
        int mid = l + (r - l) / 2;
        string ls = LCP(strs, l, mid);
        string rs = LCP(strs, mid + 1, r);
        return findCommonPrefix(ls, rs);
    }

    string findCommonPrefix(string l, string r) {
        int i, n = min(l.size(), r.size());
        for (i = 0; i < n; i++) {
            if (l[i] != r[i]) return l.substr(0, i);
        }
        return l.substr(0, n);
    }
};

// Binary search
class Solution_4 {
    string longestCommonPrefix_4(vector<string> &strs) {
        if (strs.empty()) return "";
        size_t minLen = 201;
        for (string s : strs) {
            minLen = min(minLen, s.length());
        }
        int left = 1;
        int right = minLen;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isCommonPrefix(strs, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return strs[0].substr(0, (left + right) / 2);
    }

    bool isCommonPrefix(vector<string> &strs, int len) {
        string prefix = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++) {
            // !strs[i].startWith(prefix);
            if (strs[i].substr(0, len) != prefix) return false;
        }
        return true;
    }
};
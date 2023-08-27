#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(vector<int> &A) { return A[0] > 0 && A[1] > 0 && A[2] > 0; }

    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> st(3, 0);
        int left = 0, right = 0, cnt = 0;

        while (right < n) {
            char c = s[right];
            st[c - 'a']++;
            while (check(st)) {
                cnt += n - right;
                int k = s[left++] - 'a';
                st[k]--;
            }
            right++;
        }
        return cnt;
    }
};
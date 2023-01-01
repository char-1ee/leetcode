#include <bits/stdc++.h>
using namespace std;

// Initial Greedy solution 
class Solution {
   public:
    int minimumPartition(string s, int k) {
        int cnt = 0, kk = k;
        while (kk) {
            cnt++;
            kk /= 10;
        }

        int n = s.length(), res = 0;
        if (cnt == 1) {
            for (auto c : s) {
                if (c - '0' > k) return -1;
            }
            return n;
        }
        for (int i = 0, j = 0; i < n;) {
            if (i == n - 1) {
                int num = s[i] - '0';
                if (num <= k)
                    res++;
                else
                    return -1;
                break;
            }

            while (j - i + 1 < cnt) {
                if (j == n - 1) {
                    res++;
                    return res;
                }
                j++;
            }
            // j - i + 1 == cnt
            string ss = s.substr(i, j - i + 1);
            int num = stoi(ss);
            if (num > k) {
                i = j;
            } else {  // valid substring
                i = j + 1;
            }
            res++;
        }
        return res;
    }
};
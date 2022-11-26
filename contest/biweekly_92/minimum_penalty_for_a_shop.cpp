#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int bestClosingTime(string s) {
        int n = s.length();
        int Y = 0, N = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'Y')
                Y++;
            else
                N++;
        }
        if (Y == 0)
            return 0;
        else if (N == 0)
            return n;

        int currY = 0, currN = 0;
        int minp = INT_MAX, t = 0, p;

        for (int i = 0; i < n; i++) {
            p = currN + (Y - currY);
            if (minp > p) {
                minp = p;
                t = i;
            }
            if (s[i] == 'Y')
                currY++;
            else
                currN++;
        }
        if (minp > N) return n;

        return t;
    }
};
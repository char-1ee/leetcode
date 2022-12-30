#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int closetTarget(vector<string> &words, string target, int startIndex) {
        if (words.size() == 1) return words[0] == target ? 0 : -1;
        if (words[startIndex] == target) return 0;

        int n = words.size(), res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                res = min(res, min(dist, abs(n - dist)));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
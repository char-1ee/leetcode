#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int captureForts(vector<int> &f) {
        int n = f.size(), ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (f[i] != 0) {
                if (f[i] == -f[j]) ans = max(ans, i - j - 1);
                j = i;
            }
        }
        return ans;
    }

    // More intutionly, prev stands for the starting -1 or 1, prev_index
    // stands for prev's index. Then we iterate to find the ending 1 or -1.
    int captureForts2(vector<int> &forts) {
        int n = forts.size(), ans = 0;
        int prev_index = 0, prev = forts[0];

        for (int i = 1; i < n; i++) {
            if (forts[i]) {
                if (forts[i] == -prev) ans = max(ans, i - prev_index - 1);
                prev = forts[i], prev_index = i;
            }
        }
        return ans;
    }
};
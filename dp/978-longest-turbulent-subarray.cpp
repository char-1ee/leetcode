#include <bits/stdc++.h>
using namespace std;

// DP, inc[] stands for the length of subarray ends with i-th element, which
// ends with increasing trends. Same as dec[].
class Solution {
   public:
    int maxTurbulenceSize(vector<int> &arr) {
        int n = arr.size(), res = 1;
        vector<int> dec(n, 1), inc(n, 1);
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                dec[i] = inc[i - 1] + 1;
            } else if (arr[i - 1] < arr[i]) {
                inc[i] = dec[i - 1] + 1;
            }
            res = max(res, max(inc[i], dec[i]));
        }
        return res;
    }
};
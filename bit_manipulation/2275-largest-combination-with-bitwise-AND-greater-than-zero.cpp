#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0, n = candidates.size();
        int mx = *max_element(candidates.begin(), candidates.end());

        for (int i = 1; i <= mx; i <<= 1) {
            int curr = 0;
            for (auto x : candidates) {
                if ((x & i) > 0) curr++;
            }
            res = max(res, curr);
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximizeSum(vector<int> &nums, int k) {
        int n = nums.size(), res = 0;
        sort(begin(nums), end(nums));
        int m = nums.back();
        for (int i = 0; i < k; i++) {
            res += m;
            m++;
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int> &nums) {
        int n = nums.size();
        int cnt = count(begin(nums), end(nums), 1);
        if (cnt > 0) return n - cnt;

        int g = nums[0];
        for (int i = 1; i < n; i++) {
            g = __gcd(g, nums[i]);
        }
        if (g != 1) return -1;

        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            int k = nums[i];
            for (int j = i; j < n; j++) {
                k = __gcd(nums[j], k);
                if (k == 1) mn = min(mn, j - i);
            }
        }
        return mn + n - 1;
    }
};
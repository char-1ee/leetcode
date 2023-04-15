#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        int a = nums[0], b = nums[0], mx = nums[0];
        res[0] = nums[0] * 2;
        for (int i = 1; i < n; i++) {
            a += nums[i];
            mx = max(mx, nums[i]);
            b += mx;
            res[i] = a + b;
        }
        return res;        
    }
};
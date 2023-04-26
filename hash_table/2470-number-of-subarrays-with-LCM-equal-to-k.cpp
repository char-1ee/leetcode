#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int currLcm = 1;
            for (int j = i; j < n; j++) {
                if (k % nums[j] != 0) break;
                currLcm = lcm(nums[j], currLcm);
                res += currLcm == k;
            }
        }
        return res;
    }
};
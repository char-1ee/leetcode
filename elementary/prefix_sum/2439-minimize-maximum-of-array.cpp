#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long sum = nums[0], res = nums[0];

        for (int i = 1; i < n; i++) {
            sum += nums[i];
            res = max(res, (long long)ceil(double(sum) / (i + 1)));
        }
        return res;
    }
};

// for int division:
// ceil(double(x) / (i + 1)) <=> (x + i) / (i + 1)
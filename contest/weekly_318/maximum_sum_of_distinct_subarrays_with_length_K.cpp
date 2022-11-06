#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0, sum = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            m[nums[i]]++;
        }
        if (m.size() == k) res = sum;

        for (int l = 0, r = k; r < n; l++, r++) {
            m[nums[l]]--;
            if (m[nums[l]] == 0) m.erase(nums[l]);
            m[nums[r]]++;
            sum -= nums[l];
            sum += nums[r];
            if (m.size() == k) {
                res = max(res, sum);
            }
        }
        return res;
    }
};
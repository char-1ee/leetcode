#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        vector<int> cnt(50, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) cnt[nums[i] + 50]++;
            if (i < k - 1) continue;
            if (i >= k && nums[i - k] < 0) cnt[nums[i - k] + 50]--;
            int count = 0, j;
            for (j = 0; j < 50; j++) {
                count += cnt[j];
                if (count >= x) {
                    res.push_back(j - 50);
                    break;
                }
            }
            if (count < x) res.push_back(0);
        }
        return res;
    }
};
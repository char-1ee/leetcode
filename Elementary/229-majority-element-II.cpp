#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;

        int res1 = numeric_limits<int>::min();
        int res2 = numeric_limits<int>::max();
        int cnt1 = 0, cnt2 = 0;

        // Scan 1: voting cnt
        for (int num : nums) {
            if (num == res1) {
                cnt1++;
            } else if (num == res2) {
                cnt2++;
            } else if (cnt1 == 0) {
                res1 = num;
                cnt1++;
            } else if (cnt2 == 0) {
                res2 = num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // Scan 2: validate majority
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == res1)
                cnt1++;
            else if (num == res2)
                cnt2++;
        }

        if (cnt1 * 3 > n) v.push_back(res1);
        if (cnt2 * 3 > n) v.push_back(res2);

        return v;
    }
};
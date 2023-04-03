#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int j = lower;
        for (auto num : nums) {
            if (num > j) {
                if (num - 1 == j) res.push_back(to_string(j));
                else res.push_back(to_string(j) + "->" + to_string(num - 1));
            }
            // if nums contains INT_MAX, then need check the overflow before `j = num + 1`
            if (num == upper) return res;
            j = num + 1;
        }
        if (j <= upper) {
            if (j == upper) res.push_back(to_string(upper));
            else res.push_back(to_string(j) + "->" + to_string(upper));
        }
        return res;
    }
};
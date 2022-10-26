#include <bits/stdc++.h>
using namespace std;

// increment n-1 element by 1 == decrement 1 element by 1
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX, res = 0;
        for (auto num : nums) {
            mn = min(num, mn);
        }
        for (auto num : nums) {
            res += num - mn;
        }
        return res;
    }

    int minMoves_solution2(vector<int>& nums) {
        int res = 0, mn = INT_MAX;
        for (auto num : nums) {
            res += num;
            mn = min(mn, num);
        }
        return res - mn * nums.size();
    }
};
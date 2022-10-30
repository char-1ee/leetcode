#include <bits/stdc++.h>
using namespace std;

// Two pass
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size(), mx = INT_MIN; // max target count
        unordered_map<int, int> map;
        for (auto& num : nums) {
            int rem = num % space;
            map[rem]++;
            if (mx < map[rem]) {
                mx = map[rem];
            }
        }
        int res = INT_MAX;
        for (auto& num : nums) {
            if (map[num % space] == mx)
                res = min(res, num);
        }
        return res;
    }
};

// One pass
class Solution2 {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        int res = -1, mx = 0; // current max target count
        unordered_map<int, int> map;
        sort(nums.begin(), nums.end(), greater<int>());
        for (auto& num : nums) {
            int rem = num % space;
            if (map[rem] >= mx) {
                mx = map[rem];
                res = num;
            }
            map[rem]++;
        }
        return res;
    }
};
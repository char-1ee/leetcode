#include <bits/stdc++.h>
using namespace std;

// sum(i, j) % k == 0 if sum(0, i) % k == sum(0, j) % k
class Solution {
   public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int cnt = 0, sum = 0;  // sum: curr sum ends at index i
        unordered_map<int, int> m; // map<mod, freq>
        m[0] = 1;  // initialize [0] = 1
        for (auto num : nums) {
            sum += num;

            // in cpp, mod operation will return negative
            int idx = (sum % k + k) % k;

            // cumulative count
            if (m.count(idx)) {
                cnt += m[idx];
            }
            m[idx]++;
        }
        return cnt;
    }


    int subarraysDivByK_solution2(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, sum = 0;
        unordered_map<int, int> m = {{0, 1}};
        for (auto num : nums) {
            sum += num;
            int idx = (sum % k + k) % k;
            m[idx] ++;
        }
        
        for (auto t : m) {
            cnt += t.second * (t.second - 1) / 2;
        }
        return cnt;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int subarraysWithKDistinct(vector<int> &nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int> &nums, int k) {
        int n = nums.size(), res = 0;
        int l = 0, r = 0;
        unordered_map<int, int> m;
        while (r < n) {
            int num = nums[r];
            r++;
            m[num]++;
            while (m.size() > k) {
                int num2 = nums[l];
                l++;
                m[num2]--;
                if (m[num2] == 0) m.erase(num2);
            }
            res += r - l + 1;
        }

        return res;
    }
};
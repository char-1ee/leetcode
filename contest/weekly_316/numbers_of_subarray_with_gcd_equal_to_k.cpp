#include <bits/stdc++.h>
using namespace std;

// since constraints are nums.size() in [1, 1000]
// then brute force fine all aubarrays
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr_gcd = 0; // gcd(0, n) = n
            for (int j = i; j < nums.size(); j++) {
                curr_gcd = __gcd(nums[j], curr_gcd);
                if (curr_gcd < k || curr_gcd % k != 0) break;
                if (curr_gcd == k) cnt++;
            }
        }
        return cnt;
    }

    int subarrayGCD2(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int currGcd = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % k != 0) break;
                currGcd = __gcd(nums[j], currGcd);
                res += currGcd == k;
            }
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long findTheArrayConcVal(vector<int> &nums) {
        int n = nums.size();
        long long res = 0;

        if (n == 1) return nums[0];

        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (i == j) {
                res += nums[i];
            } else {
                string x = to_string(nums[i]);
                string y = to_string(nums[j]);
                res += stoi(x + y);
            }
        }
        return res;
    }
};
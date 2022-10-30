#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt = 0, sum = 0;
        for (auto num : nums) {
            if (num % 6 == 0) {
                cnt++;
                sum += num;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
};
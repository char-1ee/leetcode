#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string originalDigits(string s) {
        int n = s.length();
        unordered_map<char, int> cnts;
        vector<int> nums(10, 0);
        for (auto c : s) cnts[c]++;

        nums[0] = cnts['z'];
        nums[2] = cnts['w'];
        nums[4] = cnts['u'];
        nums[6] = cnts['x'];
        nums[8] = cnts['g'];
        nums[1] = cnts['o'] - nums[0] - nums[4] - nums[2];
        nums[3] = cnts['h'] - nums[8];
        nums[5] = cnts['f'] - nums[4];
        nums[7] = cnts['s'] - nums[6];
        nums[9] = cnts['i'] - nums[6] - nums[8] - nums[5];

        string res = "";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < nums[i]; j++) {
                res += (i + '0');
            }
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> separateDigits(vector<int> &nums) {
        int n = nums.size();
        vector<int> res;
        stack<int> t;

        for (auto num : nums) {
            while (num) {
                t.push(num % 10);
                num /= 10;
            }
            while (!t.empty()) {
                res.push_back(t.top());
                t.pop();
            }
        }
        return res;
    }

    vector<int> separateDigits2(vector<int> &nums) {
        int n = nums.size();
        vector<int> res;
        for (auto &num : nums) {
            string s = to_string(num);
            for (auto c : s) {
                res.push_back(c - '0');
            }
        }
        return res;
    }
};
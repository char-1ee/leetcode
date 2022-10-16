#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
            string s = to_string(num);
            reverse(s.begin(), s.end());
            set.insert(stoi(s));
        }
        return set.size();
    }
};
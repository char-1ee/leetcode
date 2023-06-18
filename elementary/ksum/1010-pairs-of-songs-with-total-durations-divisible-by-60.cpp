#include <bits/stdc++.h>
using namespace std;

// Solution 1 (Signed integer overflow)
class Solution {
   public:
    int numPairsDivisibleBy60(vector<int> &time) {
        long long res = 0;
        unordered_map<int, int> mp;  // {time i, cnt of time i}
        unordered_set<int> st;       // visited
        for (auto t : time) {
            mp[t % 60]++;
        }
        for (auto &t : mp) {
            if (st.count(t.first)) continue;      // visited t
            if (t.first == 0 || t.first == 30) {  // same element
                res += t.second * (t.second - 1) / 2;
            } else {  // find two sum
                int target = 60 - t.first;
                if (!mp.count(target)) continue;
                res += mp[target] * t.second;
                st.insert(target);
            }
            st.insert(t.first);
        }
        return (int)res;
    }
};

// Solution 2'
class Solution2 {
   public:
    int numPairsDivisibleBy60(vector<int> &time) {
        int res = 0, n = time.size();
        vector<int> freq(60, 0);  // [0, 59]
        for (auto t : time) {
            if (t % 60 == 0) {
                res += freq[0];
            } else {
                res += freq[60 - t % 60];
            }
            freq[t % 60]++;
        }
        return res;
    }
};
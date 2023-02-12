#include <bits/stdc++.h>
using namespace std;

// O(32 * n)
// Because substring decimal value must be integer, so substring length is
// constrained to be 32 bit, for which we can store all substring possible
// values with extra space. Substring decimal value calculation:
// num = (num << 1) + s[i];
class Solution {
   public:
    vector<vector<int>> substringXorQueries(string s,
                                            vector<vector<int>> &queries) {
        int n = s.length();
        vector<vector<int>> res;
        unordered_map<int, pair<int, int>> m;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (!m.count(0)) m[0] = make_pair(i, i);
                continue;
            }
            long long num = 0;
            for (int j = 0; j < 32 && i + j < n; j++) {
                num = (num << 1) + (s[i + j] - '0');
                if (!m.count(num)) {
                    m[num] = make_pair(i, i + j);
                }
            }
        }

        for (auto q : queries) {
            int val = q[0] ^ q[1];
            if (m.count(val)) {
                res.push_back({m[val].first, m[val].second});
            } else {
                res.push_back({-1, -1});
            }
        }
        return res;
    }
};
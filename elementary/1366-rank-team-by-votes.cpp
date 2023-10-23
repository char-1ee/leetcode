#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string rankTeams(vector<string> &votes) {
        int n = votes.size(), m = votes[0].size();
        vector<vector<int>> mp(m, vector<int>(26, 0));
        string res = votes[0];
        for (auto v : votes) {
            for (int i = 0; i < m; i++) {
                mp[i][v[i] - 'A']++;
            }
        }

        auto comp = [&](char a, char b) {
            for (int i = 0; i < m; i++) {
                if (mp[i][a - 'A'] == mp[i][b - 'A'])
                    continue;
                else
                    return mp[i][a - 'A'] > mp[i][b - 'A'];
            }
            return a < b;
        };
        sort(res.begin(), res.end(), comp);
        return res;
    }
};
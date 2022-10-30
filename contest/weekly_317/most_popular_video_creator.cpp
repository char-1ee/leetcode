#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<vector<string>>
    mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        ll mx = 0;
        vector<vector<string>> res;

        unordered_map<string, ll> p; // popularity of a creator. creator : viewsSum
        unordered_map<string, vector<int>> m; // creator : ids

        for (int i = 0; i < n; i++) {
            string c = creators[i];
            p[c] += views[i];
            mx = max(mx, p[c]);
            m[c].push_back(i);
        }

        for (auto& t : p) {
            if (t.second == mx) {
                vector<string> tmp(2);
                tmp[0] = t.first;

                int maxv = -1;
                string id; // most viewed video id
                for (auto& k : m[t.first]) {
                    if (views[k] > maxv) {
                        maxv = views[k];
                        id = ids[k];
                    } else if (views[k] == maxv) {
                        id = min(id, ids[k]);
                    }
                }
                tmp[1] = id;

                res.emplace_back(tmp);
            }
        }
        return res;
    }
};
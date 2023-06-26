#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size(), len = queries.size();
        vector<pair<int, int>> l, times(len);
        vector<int> res(len, 0); 
        
        // logs: {time, serverId} and sort
        for (auto log : logs) {
            l.push_back({log[1], log[0]});
        }
        sort(begin(l), end(l));

        // times: {query, original index} and sort
        for (int i = 0; i < len; i++) {
            times[i] = {queries[i], i};
        }
        sort(times.begin(), times.end());

        // sliding windows
        unordered_map<int, int> mp; // server_id : cnt
        int i = 0, j = 0; // left and right -> l
        for (auto time : times) {
            int end = time.first;
            int start = max(0, end - x);
            int idx = time.second;

            while (j < m && l[j].first <= end) {
                mp[l[j].second]++;
                j++;
            }
            while (i < m && l[i].first < start) {
                int t = l[i].second;
                mp[t]--;
                if (mp[t] < 1) mp.erase(t);
                i++;
            }
            res[idx] = n - mp.size();
        }
        return res;
    }
};

// hints: x -> sliding window size
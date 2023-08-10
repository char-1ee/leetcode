#include <bits/stdc++.h>
using namespace std;

// BFS + Kahn's algo
class Solution {
   public:
    int minimumSemesters(int n, vector<vector<int>> &rs) {
        vector<int> edges[n + 1];
        vector<int> in(n + 1, 0);
        for (auto r : rs) {
            edges[r[0]].push_back(r[1]);
            in[r[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) q.push(i);
        }

        int sem = 0, cnt = 0;  // cnt of nodes visited
        while (!q.empty()) {
            int sz = q.size();
            sem++;
            for (int i = 0; i < sz; i++) {
                int t = q.front();
                q.pop();
                cnt++;
                for (auto r : edges[t]) {
                    in[r]--;
                    if (in[r] == 0) {
                        q.push(r);
                    }
                }
            }
        }
        return cnt == n ? sem : -1;
    }
};
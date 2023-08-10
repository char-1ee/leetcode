#include <bits/stdc++.h>
using namespace std;

// Kahn's algorithm
class Solution {
   public:
    bool canFinish(int n, vector<vector<int>> &ps) {
        vector<int> edges[n], res, deg(n, 0);
        for (auto p : ps) {
            edges[p[1]].push_back(p[0]);
            deg[p[0]]++;
        }

        queue<int> q;  // queue to put nodes with 0 in-degree
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for (auto p : edges[t]) {
                deg[p]--;
                if (deg[p] == 0) {
                    q.push(p);
                }
            }
        }
        return res.size() == n;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findOrder(int n, vector<vector<int>> &ps) {
        vector<int> edges[n];
        vector<int> in(n, 0);
        vector<int> A;

        for (auto p : ps) {
            edges[p[1]].push_back(p[0]);
            in[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            A.push_back(t);
            for (auto num : edges[t]) {
                in[num]--;
                if (in[num] == 0) {
                    q.push(num);
                }
            }
        }

        if (A.size() == n) {
            return A;
        } else
            return {};
    }
};
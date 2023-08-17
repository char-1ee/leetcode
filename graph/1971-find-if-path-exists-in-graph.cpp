#include <bits/stdc++.h>
using namespace std;

// DFS
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        stack<int> s;
        vector<int> visited(n, 0);
        s.push(source);
        visited[source] = 1;
        while (!s.empty()) {
            int t = s.top(); s.pop();
            if (t == destination) {
                return true;
            }
            for (auto k : graph[t]) {
                if (visited[k]) continue;
                s.push(k);
                visited[k] = 1;
            }
        }
        return false;
    }
};
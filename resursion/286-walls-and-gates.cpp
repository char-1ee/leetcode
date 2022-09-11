#include <bits/stdc++.h>
using namespace std;

// dfs, TLE
// time O(mn), worst time O(kmn) for each rooms being visited k times, while k if number of gates
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) // dfs start from gates
                    dfs(rooms, i, j, 0);
            }
        }
    }

    void dfs(vector<vector<int>>& rooms, int i, int j, int val) {
        if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size() || rooms[i][j] < val)
            return;
        rooms[i][j] = val;
        dfs(rooms, i - 1, j, val + 1);
        dfs(rooms, i + 1, j, val + 1);
        dfs(rooms, i, j - 1, val + 1);
        dfs(rooms, i, j + 1, val + 1);
    }
};

// dfs
// Compare to TLE dfs solution, we do a further check between next room value and current room
// value, which is rooms[i+1][j] and val + 1. If rooms[i+1][j] <= val + 1, we dont need to update
// rooms[i+1][j] anymore because it is temporarily optimal (nearest) to another gate rather then
// current gate that we start to dfs.
// time O(mn)
class Solution3 {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) dfs(rooms, i, j, 0);
            }
        }
    }

    void dfs(vector<vector<int>>& rooms, int i, int j, int val) {
        if (i + 1 < rooms.size() && rooms[i + 1][j] != -1 && rooms[i + 1][j] > val + 1) {
            rooms[i + 1][j] = val + 1;
            dfs(rooms, i + 1, j, val + 1);
        }
        if (i - 1 >= 0 && rooms[i - 1][j] != -1 && rooms[i - 1][j] > val + 1) {
            rooms[i - 1][j] = val + 1;
            dfs(rooms, i - 1, j, val + 1);
        }
        if (j + 1 < rooms[0].size() && rooms[i][j + 1] != -1 && rooms[i][j + 1] > val + 1) {
            rooms[i][j + 1] = val + 1;
            dfs(rooms, i, j + 1, val + 1);
        }
        if (j - 1 >= 0 && rooms[i][j - 1] != -1 && rooms[i][j - 1] > val + 1) {
            rooms[i][j - 1] = val + 1;
            dfs(rooms, i, j - 1, val + 1);
        }
    }
};


// bfs
// time O(mn), space O(mn)
class Solution2 {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) q.push({i, j});
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int i = x + dirs[k].first;
                int j = y + dirs[k].second;
                if (i < 0 || i >= m || j < 0 || j >= n || rooms[i][j] < rooms[x][y] + 1) continue;
                rooms[i][j] = rooms[x][y] + 1;
                q.push({i, j});
            }
        }
    }
};
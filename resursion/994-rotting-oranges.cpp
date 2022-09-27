#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0, freshLeft = 0;

        queue<vector<int>> q;
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) ++freshLeft;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }

        while (!q.empty() && freshLeft > 0) {
            for (int i = q.size(); i > 0; --i) {
                auto cur = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = cur[0] + dirs[k][0], y = cur[1] + dirs[k][1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                    --freshLeft;
                }
            }
            ++res;
        }
        return freshLeft > 0 ? -1 : res;
    }
};
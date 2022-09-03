#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /** dfs */
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0; // count of islands
        vector<vector<bool>> visited(m, vector<bool>(n)); // bit set of graph

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                dfs(grid, visited, i, j);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' ||
            visited[i][j])
            return;
        visited[i][j] = true;
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i, j - 1);
        dfs(grid, visited, i, j + 1);
    }

    /** bfs */
    int numIslands2(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<int> dirX{-1, 0, 1, 0}, dirY{0, -1, 0, 1};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                cnt++;
                queue<int> q{{i * n + j}};
                while (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int x = dirX[k] + t / n;
                        int y = dirY[k] + t % n;
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' ||
                            visited[x][y])
                            continue;
                        visited[x][y] = true;
                        q.push(x * n + y);
                    }
                }
            }
        }
        return cnt;
    }
};
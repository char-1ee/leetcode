#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxFish(vector<vector<int>> &grid) {
        int mx = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] > 0) mx = max(mx, dfs(grid, i, j));
        return mx;
    }
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
            grid[i][j] > 0) {
            int cnt = grid[i][j];
            grid[i][j] = 0;
            return cnt + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) +
                   dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
        }
        return 0;
    }
};
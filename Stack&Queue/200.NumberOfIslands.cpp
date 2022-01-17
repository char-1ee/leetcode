class Solution {
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' ||visited[i][j] )    
            return;
        visited[i][j] = true;
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i, j - 1);
        dfs(grid, visited, i, j + 1);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;    // count of islands
        vector<vector<bool>> visited(m, vector<bool>(n)); // bit set of graph
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                dfs(grid, visited, i, j);
                cnt++;
            }
        }
        return cnt;
    }
};
package resursion_dp;

class Solution {

    private int[][] dirs = new int[][] { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int res = 0;
        int[][] visited = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = Math.max(res, dfs(matrix, i, j, visited));
            }
        }
        return res;
    }

    private int dfs(int[][] matrix, int i, int j, int[][] visited) {
        int res = 1, m = matrix.length, n = matrix[0].length;
        if (visited[i][j] != 0)
            return visited[i][j];
        for (int[] dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j])
                continue;
            int tmp = 1 + dfs(matrix, x, y, visited);
            res = Math.max(res, tmp);
        }
        visited[i][j] = res;
        return res;

    }
}
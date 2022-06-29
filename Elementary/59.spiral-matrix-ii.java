package elementary;
/*
 * @lc app=leetcode id=59 lang=java
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
    public int[][] generateMatrix(int n) {
        if (n == 1) {
            return new int[][] { { 1 } };
        }

        // square matrix
        int[][] mat = new int[n][n];
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            int end = n - layer - 1;
            for (int ptr = layer; ptr <= end; ptr++) {
                mat[layer][ptr] = cnt++;
            }
            for (int ptr = layer + 1; ptr <= end; ptr++) {
                mat[ptr][end] = cnt++;
            }
            for (int ptr = end - 1; ptr >= layer; ptr--) {
                mat[end][ptr] = cnt++;
            }
            for (int ptr = end - 1; ptr >= layer + 1; ptr--) {
                mat[ptr][layer] = cnt++;
            }
        }
        return mat;
    }
}
// @lc code=end

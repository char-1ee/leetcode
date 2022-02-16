class Solution {

    /** Rotate Groups of Four Cells */
    public void rotate1(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) { // CAUTION
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }

    /*
     * Clockwise Rotate
     * first reverse up to down, then swap the symmetry
     * 1 2 3    7 8 9    7 4 1
     * 4 5 6 => 4 5 6 => 8 5 2
     * 7 8 9    1 2 3    9 6 3
     */
    public void rotate2(int[][] matrix) {
        int n = matrix.length;
        // reverse(matrix.begin(), matrix.end());
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int[] tmp = matrix[i];
            matrix[i] = matrix[j];
            matrix[j] = tmp;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // swap(matrix[i][j], matrix[j][i]);
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }

    /*
     * Anti-clockwise rotate
     * first reverse left to right, then swap the symmetry
     * 1 2 3    3 2 1    3 6 9
     * 4 5 6 => 6 5 4 => 2 5 8
     * 7 8 9    9 8 7    1 4 7
     */
    // void anti_rotate(vector<vector<int> > &matrix) {
    //     for (auto vi : matrix) reverse(vi.begin(), vi.end());
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = i + 1; j < matrix[i].size(); ++j)
    //             swap(matrix[i][j], matrix[j][i]);
    //     }
}
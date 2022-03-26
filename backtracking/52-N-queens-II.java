package backtracking;

/** For detailed, refer to cpp solution */
class Solution {
    
    private boolean[] diag;
    private boolean[] antiDiag;
    private boolean[] cols;
    private int res = 0;
    
    public int totalNQueens(int n) {
        if (n == 1) return 1;
        diag = new boolean[2*n];
        antiDiag = new boolean[2*n];
        cols = new boolean[n];
        backtrack(0, n);
        return res;
    }
    
    private void backtrack(int row, int n) {
        if (row == n) res++;
        for (int col = 0; col < n; col++) {
            int x1 = col - row  + n;
            int x2 = row + col;
            if (diag[x1] || antiDiag[x2] || cols[col])
                continue;
            diag[x1] = true;
            antiDiag[x2] = true;
            cols[col] = true;
            backtrack(row + 1, n);
            diag[x1] = false;
            antiDiag[x2] = false;
            cols[col] = false;
        }
    }
}
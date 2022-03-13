
class Solution {

    private boolean[] diag; 
    private boolean[] anti_diag;
    private boolean[] cols;

    public int totoalQueens(int n) {
        if (n == 1) return 1;

        diag = new boolean[2 * n];
        anti_diag = new boolean[2 * n];
        cols = new boolean[n];

        return backtrack(0, n);
    }

    public int backtrack(int row, int n) {
        // if row larger than n, there is a solution
        if (row == n) return 1;
        int res = 0;
        for (int col = 0; col < n; col++) {

        }

    }


}
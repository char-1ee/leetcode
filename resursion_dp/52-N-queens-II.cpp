class Solution {
public:
    // backtracking
    int totalNQueens(int n) {
        if (n == 1) return 1;
        int res = 0;
        vector<bool> diag(2*n), anti_diag(2*n), cols(n);
        backtrack(0, n, diag, anti_diag, cols, res);
        return res;
    }

    void backtrack(int row, int n, vector<bool>& diag, vector<bool>& anti_diag, vector<bool>& cols, int &res) {
        if (row == n) res++;
        for (int col = 0; col < n; ++col) {
            int idx1 = row - col + n; // current diagonal index
            int idx2 = row + col; // current anti-diagonal index
            
            if (diag[idx1] || anti_diag[idx2] || cols[col]) 
                continue;
            // set visited
            diag[idx1] = anti_diag[idx2] = cols[col] = true;

            backtrack(row + 1, n, diag, anti_diag, cols, res);
            
            // recovery for next solution to be found
            diag[idx1] = anti_diag[idx2] = cols[col] = false;
        }
    }

    // an amazing method i saw
    int totalNQueens(int n, int i = 0, int c = 0, int d = 0, int a = 0) {
        if (i == n) return 1;
        int ret = 0;
        for (int j = 0; j < n; j++) {
            int x = 1 << j, y = 1 << (i - j + n - 1), z = 1 << i + j;
            if ((c & x) || (d & y) || (a & z)) continue ;
            ret += totalNQueens(n, i + 1, c ^ x, d ^ y, a ^ z);
        }
        return ret;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        vector<vector<char>> row(9, vector<char>(9, 0));
        vector<vector<char>> col(9, vector<char>(9, 0));
        vector<vector<char>> box(9, vector<char>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == '.') continue;
                int c = grid[i][j] - '1'; // val of a cell as index
                if (row[i][c] || col[c][j] || box[3 * (i / 3) + j / 3][c])
                    return false;
                row[i][c] = 1;
                col[c][j] = 1;
                box[3 * (i / 3) + j / 3][c] = 1;
            }
        }
        return true;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        // arr[idx][val]: idx stands for n-th row/col/box, val stands for appearance of certain val
        vector<vector<char>> row(9, vector<char>(9, 0));
        vector<vector<char>> col(9, vector<char>(9, 0));
        vector<vector<char>> box(9, vector<char>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == '.') continue;
                int c = grid[i][j] - '1'; // val
                if (row[i][c] || col[j][c] || box[3 * (i / 3) + j / 3][c]) return false;
                row[i][c] = 1;
                col[j][c] = 1;
                box[3 * (i / 3) + j / 3][c] = 1;
            }
        }
        return true;
    }
};

// To save space, encoded press with string
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                string t = "(" + to_string(board[i][j]) + ")";
                string row = to_string(i) + t, col = t + to_string(j),
                       cell = to_string(i / 3) + t + to_string(j / 3);
                if (st.count(row) || st.count(col) || st.count(cell)) return false;
                st.insert(row);
                st.insert(col);
                st.insert(cell);
            }
        }
        return true;
    }
};
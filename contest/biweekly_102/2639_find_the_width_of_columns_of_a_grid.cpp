#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findColumnWidth(vector<vector<int>> &grid) {
        vector<int> res;

        int m = grid.size(), n = grid[0].size();
        for (int col = 0; col < n; col++) {
            int len = 0;
            for (int row = 0; row < m; row++) {
                string s = to_string(grid[row][col]);
                len = max(len, (int)s.length());
            }
            res.push_back(len);
        }
        return res;
    }
};
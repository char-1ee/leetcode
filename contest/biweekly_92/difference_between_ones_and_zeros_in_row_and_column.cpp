#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> oneRows(m), oneCols(n);
        vector<int> zeroRows(m), zeroCols(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    oneRows[i]++;
                    oneCols[j]++;
                } else {
                    zeroRows[i]++;
                    zeroCols[j]++;
                }
            }
        }

        vector<vector<int>> diff(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff[i][j] =
                    oneRows[i] + oneCols[j] - zeroRows[i] - zeroCols[j];
            }
        }
        return diff;
    }
};
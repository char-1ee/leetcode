class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> res;
        
        if (m == 1) {
            return matrix[0];
        } else if (n == 1) {
            for (auto num : matrix) 
                res.emplace_back(num[0]);
            return res;
        }
        
        int up = 0, down = m - 1;
        int left = 0, right = n - 1;
        
        while (res.size() < n * m) {
            for (int i = left; i <= right && res.size() < n * m; i++) {
                res.emplace_back(matrix[up][i]);
            }      
            for (int i = up + 1; i < down && res.size() < n * m; i++) {
                res.emplace_back(matrix[i][right]);
            }
            for (int i = right; i >= left && res.size() < n * m; i--) {
                res.emplace_back(matrix[down][i]);
            }
            for (int i = down - 1; i >= up + 1 && res.size() < n * m; i--) {
                res.emplace_back(matrix[i][left]);
            }
            left++; right--; up++; down--;
        }
        return res;
    }
};
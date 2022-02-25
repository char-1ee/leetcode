class Solution {
public:
    // n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
    // an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / n][mid % n] > target) right = mid;
            else if (matrix[mid / n][mid % n] < target) left = mid + 1;
            else return true;
        }
        return false;
    }

    // two searches
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target > matrix[mid][0]) left = mid + 1;
            else if (target < matrix[mid][0]) right = mid;
            else return true;
        }
        int tmp = (right > 0) ? right - 1 : right;
        left = 0, right = matrix[0].size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[tmp][mid] == target) return true;
            if (matrix[tmp][mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
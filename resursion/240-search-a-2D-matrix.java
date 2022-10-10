package resursion;

class Solution {
    private int[][] matrix;
    private int target;
    
    public boolean searchMatrix(int[][] matrix, int target) {
        this.matrix = matrix;
        this.target = target;
        int m = matrix.length, n = matrix[0].length;
        if (m == 1 && n == 1)
            return target == matrix[0][0];
        return searchMatrix(0, 0, n-1, m-1);
    }
    
    /**
     * helper function
     * @param left  leftmost-col            
     * @param up    top-row
     * @param right rightmost-col
     * @param down  bottom-row
     * @return
     * 
     */
    private boolean searchMatrix(int left, int up, int right, int down) {
        if (left > right || up > down)
            return false;
        else if (target < matrix[up][left] || target > matrix[down][right]) 
            return false;
        
        int mid = left + (right - left) / 2;
        
        // find the row that matrix[row-1][mid] < target < matrix[row][mid]
        int row = up;
        while (row <= down && matrix[row][mid] <= target) {
            if (matrix[row][mid] == target)
                return true;
            row++;
        }
        
        return searchMatrix(left, row, mid-1, down) || searchMatrix(mid+1, up, right, row -1);
    }
}
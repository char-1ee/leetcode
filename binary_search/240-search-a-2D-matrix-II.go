func searchMatrix(matrix [][]int, target int) bool {
    m, n := len(matrix), len(matrix[0])
    i, j := 0, n-1
    for i < m && j >= 0 {
        if matrix[i][j] == target { // check quality first
            return true
        }
        if matrix[i][j] < target {
            i++
        } else {
            j--
        }
    }
    return false
}
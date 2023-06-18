package elementary;

import java.util.ArrayList;
import java.util.List;

class Solution1 {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length; // rows
        int n = matrix[0].length; // cols
        List<Integer> res = new ArrayList<Integer>();

        if (m == 1) {
            for (int num : matrix[0]) {
                res.add(num);
            }
            return res;
        } else if (n == 1) {
            for (int[] num : matrix) {
                res.add(num[0]);
            }
            return res;
        }

        int l = 0, r = n - 1, u = 0, d = m - 1;
        int x = 0, y = 0;
        int cnt = 0;
        while (l <= r && u <= d) {
            if (cnt % 4 == 0) {
                for (int i = l; i <= r; i++) {
                    res.add(matrix[x][i]);
                }
                y = r;
                u++;
            } else if (cnt % 4 == 1) {
                for (int i = u; i <= d; i++) {
                    res.add(matrix[i][y]);
                }
                x = d;
                r--;
            } else if (cnt % 4 == 2) {
                for (int i = r; i >= l; i--) {
                    res.add(matrix[x][i]);
                }
                y = l;
                d--;
            } else if (cnt % 4 == 3) {
                for (int i = d; i >= u; i--) {
                    res.add(matrix[i][y]);
                }
                x = u;
                l++;
            }
            cnt++;
        }
        return res;
    }
}

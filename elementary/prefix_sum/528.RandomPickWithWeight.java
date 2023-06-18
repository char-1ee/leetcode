import java.util.*;

class Solution {

    private int[] sum;
    private Random rand;
    
    public Solution(int[] w) {
        for (int i = 1; i < w.length; i++) {
            w[i] += w[i-1];
        }
        this.sum = w;
        this.rand = new Random();
    }
    
    public int pickIndex() {
        int n = sum.length;
        // int target = rand.nextInt() % sum[n-1];
        // remind of how rand range is choosed: https://leetcode.com/problems/random-pick-with-weight/discuss/154044/Java-accumulated-freq-sum-and-binary-search
        int target = rand.nextInt(sum[n - 1]) + 1;
        
        // bs: find upper bound
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] == target) return mid;
            else if (sum[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
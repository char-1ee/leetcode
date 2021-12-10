class Solution {
   
/**
 * Brute Force;
 * Time complexity: O(n^2)
 */
    public int minSubArrayLen1(int target, int[] nums) {
        int n = nums.length;
        int sum = 0, res = n;
         
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = i; j < n; j++){
                sum += nums[j];
                cnt = j - i + 1;
                if (sum >= target) break;
            }
            res = Math.min(res, cnt);
        }
        return res;
    }
 
/**
 * Sliding Window Algorithm;
 * Time complexity: O(n)
 */
    public int minSubArrayLen2(int target, int[] nums){
        int n = nums.length;
        int left = 0, right = 0, sum = 0;
        int l = Integer.MAX_VALUE;
        // Edge case: 5, [1, 1, 1, 1]
        
        while (right < n){
            sum += nums[right];
            while (sum >= target){
                l = Math.min(l, right - left + 1);
                sum -= nums[left++];
            }
            right++;
        }
        // For Edge Case
        return l == Integer.MAX_VALUE ? 0 : l;
    }
}

/**
 * Binary Search;
 * Time Complexity: O(nlogn);
 * Links: https://grandyang.com/leetcode/209/
 */

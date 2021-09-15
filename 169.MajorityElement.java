import java.util.Arrays;

class Solution {

    /** 
     * Time: O(nlogn); Space: O(1)
     */
    public int majorityElement1(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];   // Assume majority always exists
    }
    
    /**
     * Moore voting algorithm: https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
     * Time: O(n); Space: O(1)
     */
    public int majorityElement2(int[] nums) {
        int res = Integer.MIN_VALUE;
        int cnt = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (cnt == 0) res = nums[i];

            if (nums[i] != res) {
                cnt--;
            } else {
                cnt++;
            }
        }
        return res;
    }
}

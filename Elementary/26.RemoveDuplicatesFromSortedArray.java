package elementary;

class Solution {
    /**
     * Approach: Slow-Fast pair pointers;
     * Links: https://grandyang.com/leetcode/26/
     */
    public int removeDuplicates1(int[] nums) {
        // Slow pointer k
        int k = 1;
        // Edge case: empty nums[] for which i = 1 exceed length bound;
        // and not to need the i == 0 check in the loop:
        // for (i == 0 || nums[i] != nums[i-1]){}
        if (nums.length == 0)
            return 0;
        // Fast pointer i
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1])
                nums[k++] = nums[i];
        }
        return k;
    }

    /**
     * One pointer In-place: by applying enhanced for-each loop.
     */
    public int removeDuplicates2(int[] nums) {
        int i = nums.length > 0 ? 1 : 0;
        for (int n : nums) {
            if (n != nums[i - 1])
                nums[i++] = n;
        }
        return i;
    }
}

/**
 * We will be using a two-pointer approach where one pointer iterates over the original set of elements 
 * and another one that keeps track of the next "empty" location in the array 
 * or the next location that can be overwritten in the array.
 */
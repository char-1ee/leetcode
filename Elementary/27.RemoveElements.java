package Elementary;

class Solution {
    public int removeElement(int[] nums, int val) {
        int k = 0, n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }

}

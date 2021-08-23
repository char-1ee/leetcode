class Solution {
    public int[] shuffle(int[] nums, int n) {
        // involve two pointers into loop
        int pt1 = 0, pt2 = n;  
        int[] res = new int[nums.length];
        for (int i = 0; i < 2 * n; i += 2) {
            res[i] = nums[pt1++];
            res[i + 1] = nums[pt2++];
        }
        return res;
    }
}

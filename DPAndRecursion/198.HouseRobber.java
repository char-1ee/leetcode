class Solution {
    /** Bottom-up DP */
    public int rob(int[] nums) {
        if (nums.length == 1)
            return nums[0];
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.length - 1];
    }

    /** Top-down */
    private HashMap<Integer, Integer> m = new HashMap<>();
    private int[] nums;

    private int dp(int i) {
        if (i == 0)
            return nums[0];
        if (i == 1)
            return Math.max(nums[0], nums[1]);
        if (!m.containsKey(i))
            m.put(i, Math.max(dp(i - 2) + nums[i], dp(i - 1)));
        return m.get(i);
    }

    public int rob2(int[] nums) {
        this.nums = nums;
        return dp(nums.length - 1);
    }
}
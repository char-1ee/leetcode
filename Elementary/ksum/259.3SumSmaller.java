package elementary.ksum;

import java.util.Arrays;

class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        int cnt = 0, n = nums.length;
        Arrays.sort(nums);
        if (n < 3 || 3 * nums[0] >= target)
            return cnt;
        for (int k = 0; k < n - 2; k++) {
            // no need to remove duplicate coz cnt is counted by indexes
            // if (k > 0 && nums[k] == nums[k+1]) continue;
            int i = k + 1, j = n - 1;
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) {
                    cnt += j - i; // trick
                    i++;
                } else {
                    j--;
                }
            }
        }
        return cnt;
    }
}

package elementary.sliding_window;

class Solution {

    /**
     * Sliding Window Algorithm (Two pointers)
     * Time complexity: O(n)
     */
    public int minSubArrayLen1(int target, int[] nums) {
        int n = nums.length;
        int left = 0, right = 0, sum = 0;
        int l = Integer.MAX_VALUE;
        // Edge case: 5, [1, 1, 1, 1]

        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                l = Math.min(l, right - left + 1);
                sum -= nums[left++];
            }
            right++;
        }
        // For Edge Case
        return l == Integer.MAX_VALUE ? 0 : l;
    }

    /**
     * Brute force with sums[n]
     * Time: O(n^2)
     */
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length, res = Integer.MAX_VALUE;
        int[] sums = new int[n];
        sums[0] = nums[0];
        for (int k = 1; k < n; k++) {
            sums[k] = sums[k - 1] + nums[k];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((sums[j] - sums[i] + nums[i]) >= target) {
                    res = Math.min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == Integer.MAX_VALUE ? 0 : res;
    }

    /**
     * Binary search
     * Time: O(nlogn)
     */
    public int minSubArrayLen2(int target, int[] nums) {
        if (nums == null || target < 0) {
            throw new IllegalArgumentException("Input array is null");
        }

        int len = nums.length;
        int start = 1;
        int end = len;
        int minLen = len + 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int foundWindowSize = windowExists(nums, target, mid);
            if (foundWindowSize > 0) {
                end = foundWindowSize - 1;
                minLen = foundWindowSize;
            } else {
                start = mid + 1;
            }
        }

        return minLen % (len + 1);
    }

    private int windowExists(int[] nums, int target, int maxWindowSize) {
        int foundWindowSize = 0;
        for (int i = 0; i < nums.length; i++) {
            target -= nums[i];
            foundWindowSize++;

            if (i >= maxWindowSize) {
                foundWindowSize--;
                target += nums[i - maxWindowSize];
            }

            if (target <= 0) {
                return foundWindowSize;
            }
        }

        return -1;
    }

}

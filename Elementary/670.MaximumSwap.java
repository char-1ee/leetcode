package elementary;

class Solution {
    public int maximumSwap(int num) {
        char[] nums = String.valueOf(num).toCharArray();
        int n = nums.length; 
        int[] buckets = new int[10];
        for (int i = 0; i < n; i++) {
            buckets[nums[i] - '0'] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int k = 9; k > nums[i] - '0'; k--) {
                if (buckets[k] > i) {
                    char tmp = nums[i];
                    nums[i] = nums[buckets[k]];
                    nums[buckets[k]] = tmp;
                    return Integer.valueOf(new String(nums));
                }
            }
        }
        return num;
    }
}
package binary_search_tree;

import java.util.TreeSet;

class Solution {
    public boolean containNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (nums.length < 2) return false;
        if (k == 0) return false;

        TreeSet<Long> set = new TreeSet<>(); // Long avoid stack overflow
        for (int i = 0; i< nums.length; i++) {
            Long floor = set.floor((long)nums[i] + t);
            if (floor != null && floor >= (long)nums[i] - t)
                return true;
            set.add((long)nums[i]);
            if (i >= k) set.remove((long)nums[i - k]);
        }
        return false;
    }
}

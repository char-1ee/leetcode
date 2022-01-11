package HashTable;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {

    /** HashMap; O(n) */
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            if (map.containsKey(nums[i]))
                return true;
            map.put(nums[i], i);
        }
        return false;
    }

    /** HashSet; O(n) */
    public boolean containsDuplicate2(int[] nums) {
        Set<Integer> st = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (!st.add(nums[i])) // also can consider addAll()
                return true;
        }
        return false;
    }

    /** Sorting; O(nlogn) */
    public boolean containsDuplicate3(int[] nums) {
        if (nums == null || nums.length < 2) // accelerate
            return false;
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
}
package hash_table;

import java.util.Arrays;
import java.util.HashSet;

class Solution {
    /** Two sets, retainAll() */
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> s1 = new HashSet<>();
        HashSet<Integer> s2 = new HashSet<>();
        for (int num : nums1)
            s1.add(num);
        for (int num : nums2)
            s2.add(num);
        
        s1.retainAll(s2);
        int[] res = new int[s1.size()];
        int i = 0;
        for (int n : s1) {
            res[i++] = n;
        }
        return res;
    }

    /** One set */
    public int[] intersection1(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<>();
        HashSet<Integer> s = new HashSet<>();
        for (int num : nums1) 
            set.add(num);
        for (int num : nums2) {
            if (set.contains(num))
                s.add(num);
        }
        int[] res = new int[s.size()];
        int i = 0;
        for (int n : s)
            res[i++] = n;
        return res;
    }

    /** Binary search */
    public int[] intersection2(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<>();
        Arrays.sort(nums1);
        for (int num : nums2) {
            if (bs(nums1, num))
                set.add(num);
        }
        int[] res = new int[set.size()];
        int i = 0;
        for (int n : set) {
            res[i++] = n;
        }
        return res;
    }
    
    private boolean bs(int[] nums, int target) {
        if (nums == null || nums.length == 0) return false;
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
}
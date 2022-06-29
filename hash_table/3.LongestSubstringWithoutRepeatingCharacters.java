package hash_table;
import java.util.HashSet;
import java.util.Set;

class Solution {

    /** method 1 */
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if (n == 0) return 0;
        int left = 0, res = Integer.MIN_VALUE, i = 0;
        Set<Character> set = new HashSet<>();
        while (i < n) {
            if (!set.contains(s.charAt(i))) {
                set.add(s.charAt(i));
                i++;
                res = Math.max(res, (int)set.size());
            } else {
                set.remove(s.charAt(left));
                left++;
            }
        }
        return res;
    }
}
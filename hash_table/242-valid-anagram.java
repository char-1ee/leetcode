package hash_table;

import java.util.Arrays;
import java.util.HashMap;

class Solution {
    /** hash map */
    public boolean isAnagram(String s, String t) {
        int m = s.length(), n = t.length();
        if (m != n)
            return false;
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < m; i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
            map.put(t.charAt(i), map.getOrDefault(t.charAt(i), 0) - 1);
        }
        for (Integer v : map.values()) {
            if (v != 0)
                return false;
        }
        return true;
    }

    /** hash table */
    public boolean isAnagram2(String s, String t) {
        if (s.length() != t.length())
            return false;
        int[] table = new int[26];
        for (int i = 0; i < t.length(); i++) {
            table[s.charAt(i) - 'a']++;
            table[t.charAt(i) - 'a']--;
        }
        for (int num : table) {
            if (num != 0)
                return false;
        }
        return true;
    }

    /** sorting */
    public boolean isAnagram3(String s, String t) {
        if (s.length() != t.length())
            return false;
        char[] s1 = s.toCharArray();
        char[] s2 = t.toCharArray();
        Arrays.sort(s1);
        Arrays.sort(s2);
        return Arrays.equals(s1, s2);
    }

}

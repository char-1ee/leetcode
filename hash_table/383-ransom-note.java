package hash_table;

import java.util.HashMap;

class Solution {
    public boolean canConstruct(String t, String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        for (int j = 0; j < t.length(); j++) {
            char c = t.charAt(j);
            if (!map.containsKey(c))
                return false;
            if (map.get(c) <= 0)
                return false;
            map.put(c, map.get(c) - 1);
        }
        return true;
    }
}
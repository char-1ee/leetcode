package hash_table;
import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> m = new HashMap<>() {{
            put('I', 1);
            put('V', 5);
            put('X', 10);
            put('L', 50);
            put('C', 100);
            put('D', 500);
            put('M', 1000);
        }};
        
        int res = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            int curr = m.get(s.charAt(i));
            if (i == n - 1 || m.get(s.charAt(i)) >= m.get(s.charAt(i + 1)) ) {
                res += curr;
            } else 
                res -= curr;
        }
        return res;
    }
}
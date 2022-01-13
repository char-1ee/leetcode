package Elementary;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

    /** String concantenation */
    public List<String> fizzBuzz(int n) {
        List<String> res = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            StringBuilder sb = new StringBuilder();
            if (i % 3 == 0)
                sb.append("Fizz");
            if (i % 5 == 0)
                sb.append("Buzz");
            if (sb.length() == 0)
                sb.append(i);
            res.add(sb.toString());
        }
        return res;
    }

    /** Hash map */
    public List<String> fizzBuzz2(int n) {
        List<String> res = new ArrayList<>();
        Map<Integer, String> map = new HashMap<>();
        map.put(3, "Fizz");
        map.put(5, "Buzz");

        for (int i = 1; i <= n; i++) {
            String str = "";
            for (Integer key : map.keySet()) {
                if (i % key == 0)
                    str += map.get(key);
            }
            if (str.equals(""))
                str += Integer.toString(i);
            res.add(str);
        }
        return res;
    }
}
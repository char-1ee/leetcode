package hash_table;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public String reformatDate(String date) {
        StringBuilder sb = new StringBuilder();
        Map<String, String> m = new HashMap<>(){{
            put("Jan", "01");
            put("Feb", "02");
            put("Mar", "03");
            put("Apr", "04");
            put("May", "05");
            put("Jun", "06");
            put("Jul", "07");
            put("Aug", "08");
            put("Sep", "09");
            put("Oct", "10");
            put("Nov", "11");
            put("Dec", "12");
        }};
        
        String[] strs = date.split("\\s");
        sb.append(strs[2]).append("-");
        sb.append(m.get(strs[1])).append("-");
        if (strs[0].length() < 4) {
            sb.append("0").append(strs[0].substring(0, 1));
        } else {
            sb.append(strs[0].substring(0, 2));
        }
        return sb.toString();
    }
}
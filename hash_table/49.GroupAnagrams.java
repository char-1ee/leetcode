import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        List<List<String>> res = new ArrayList<>();
        Map<String, List<Integer>> map = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            String str = strs[i];
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            
            if (!map.containsKey(sorted)) {
                map.put(sorted, new ArrayList<>());
            }
            map.get(sorted).add(i);
        }
        
        for (List<Integer> arr : map.values()) {
            List<String> list = new ArrayList<>();
            for (Integer i : arr) {
                list.add(strs[i]);
            }
            res.add(list);
        }
        return res;
    }
}
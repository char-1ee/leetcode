package elementary;

class Solution {
    public String addBoldTag(String s, String[] words) {

        int n = s.length();
        boolean[] bolds = new boolean[n];
        // for (String word : words) {
        //     int len = word.length();
        //     int start = s.indexOf(word);
        //     if (start == -1) continue;
        //     for (int k = 0; k < len; k++) {
        //         if (bolds[start + k] == false)
        //             bolds[start + k] = true;
        //     }
        // }
        
        // "aaabbcc" ["a","b","c"]
        for (int i = 0, end = 0; i < n; i++) {
            for (String word : words) {
                if (s.startsWith(word, i)) {
                    end = Math.max(end, i + word.length());
                }
            }
            bolds[i] = end > i;
        }

        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < n; i++) {
            if (bolds[i] == false) {
                sb.append(s.charAt(i));
            } else {
                int j = i;
                while (j < n && bolds[j])
                    j++;
                sb.append("<b>" + s.substring(i, j) + "</b>");
                i = j - 1;
            }
        }
        return sb.toString();
    }
}

/**
 * Using a extra boolean array to record indexes:
 * https://leetcode.com/problems/add-bold-tag-in-string/discuss/104248/Java-Solution-boolean-array
 * 
 */
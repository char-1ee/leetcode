package backtracking;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
    /** backtracking */
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        LinkedList<String> sub = new LinkedList<>();
        backtrack(res, sub, s, 0);
        return res;
    }

    private boolean isPalindrome(String s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j))
                return false;
        }
        return true;
    }

    private void backtrack(List<List<String>> res, LinkedList<String> sub, String s, int start) {
        if (start == s.length()) {
            res.add(new LinkedList<String>(sub));
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                String str = s.substring(start, i + 1);
                sub.add(str);
            } else {
                continue;
            }
            backtrack(res, sub, s, i + 1);
            sub.removeLast();
        }
    }

    /** TODO: DP */
}
package backtracking;

import java.util.ArrayList;
import java.util.List;

class Solution {
    
    // when size is countable, use array rather than hashmap to contain k-v pairs
    private String[] map = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits.isEmpty()) {
            return res;
        }
        // StringBuilder saves space when string concatenation
        StringBuilder sb = new StringBuilder(""); 
        backtrack(res, sb, digits, 0);
        return res;
    }
    
    private void backtrack(List<String> res, StringBuilder track, String digits, int idx) {
        if (track.length() == digits.length()) {
            res.add(track.toString());
            return;
        }
        // different string to iterate through in every level
        String letters = map[digits.charAt(idx) - '0'];
        for (int i = 0; i < letters.length(); i++) {
            track.append(letters.charAt(i));
            backtrack(res, track, digits, idx + 1);
            track.deleteCharAt(track.length() - 1);
        }
    }
}

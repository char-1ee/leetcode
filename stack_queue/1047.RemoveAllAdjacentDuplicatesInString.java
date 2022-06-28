package stack_queue;

import java.util.*;

class Solution {
    public String removeDuplicates(String str) {
        Stack<Character> s = new Stack<>();
        for (char c : str.toCharArray()) {
            if (s.empty() || c != s.peek()) {
                s.push(c);
            } else {
                s.pop();
            }
        }

        String res = "";
        while (!s.empty()) {
            res = s.pop() + res;
        }
        return res;
    }
}
import java.util.Stack;

class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> s = new Stack<>();
        for (char c : num.toCharArray()) {
            while (k > 0 && !s.empty() && s.peek() > c) {
                s.pop();
                k--;
            }
            if (c == '0' && s.empty())
                continue;
            s.push(c);
        }

        // when there k has not decrease
        while (!s.empty() && k > 0) {
            s.pop();
            k--;
        }
        if (s.empty())
            return "0";

        StringBuilder sb = new StringBuilder("");
        while (!s.empty()) {
            sb.append(s.pop());
        }
        return sb.reverse().toString();
    }
}

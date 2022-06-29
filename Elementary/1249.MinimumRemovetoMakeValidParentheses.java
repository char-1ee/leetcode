import java.util.Stack;

class Solution {
    /** mark invalid parantheses */
    public String minRemoveToMakeValid(String s) {
        StringBuilder sb = new StringBuilder(s); // avoid TLE
        int n = sb.length();
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            if (sb.charAt(i) == '(')
                stack.push(i);
            else if (sb.charAt(i) == ')') {
                if (stack.isEmpty())
                    sb.setCharAt(i, '*');
                else
                    stack.pop();
            }
        }
        while (!stack.isEmpty()) {
            sb.setCharAt(stack.pop(), '*');
        }
        return sb.toString().replaceAll("\\*", "");
    }
}
package mathematic;

import java.util.Stack;

class Solution {
    public int calculate(String s) {
        int n = s.length();
        if (n == 0)
            return 0;
        char currOp = '+';
        int currNum = 0, tmp = 0;
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c <= '9' && c >= '0') {
                currNum = (c - '0') + currNum * 10;
            }
            // cannot use `else if` here
            if ((c > '9' || c < '0') && c != ' ' || i == (n - 1)) { // c is now operator or last number in string
                if (currOp == '+')
                    tmp = currNum;
                else if (currOp == '-')
                    tmp = -currNum;
                else if (currOp == '*')
                    tmp = stack.pop() * currNum;
                else if (currOp == '/')
                    tmp = stack.pop() / currNum;
                currOp = c; // update current operator
                currNum = 0; // update current number
                stack.push(tmp);
            }

        }
        int res = 0;
        while (!stack.isEmpty()) { // sum up remainder in stack
            res += stack.pop();
        }
        return res;
    }
}

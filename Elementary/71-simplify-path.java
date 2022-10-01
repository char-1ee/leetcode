package elementary;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        String[] ss = path.split("/");
        
        for (String s : ss) {
            if (!stack.empty() && s.equals("..")) {
                stack.pop();
            } else if (!s.equals(".") && !s.equals("") && !s.equals("..")) {
                stack.push(s);
            }
        }
        
        List<String> list = new ArrayList<>(stack);
        return "/" + String.join("/", list);
    }
}
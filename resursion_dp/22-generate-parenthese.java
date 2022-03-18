package resursion_dp;

import java.util.ArrayList;
import java.util.List;

class Solution {

    // backtracking 1
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrack(n, n, "", res);
        return res;
    }

    public void backtrack(int left, int right, String s, List<String> res) {
        if (left < 0 || right < 0 || left > right)
            return;
        if (left == 0 && right == 0) {
            res.add(s);
            return;
        }
        backtrack(left - 1, right, s + "(", res);
        backtrack(left, right - 1, s + ")", res);
    }

    // backtracking 2
    public List<String> generateParenthesis2(int n) {
        List<String> res = new ArrayList<>();
        backtrack2(0, 0, "", res, n);
        return res;
    }

    public void backtrack2(int left, int right, String s, List<String> res, int n) {
        if (s.length() == n + n) {
            res.add(s);
            return;
        }
        if (left < n)
            backtrack2(left + 1, right, s + "(", res, n);
        if (right < left)
            backtrack2(left, right + 1, s + ")", res, n);
    }

    // an iterative method :
    // https://leetcode.com/problems/generate-parentheses/discuss/10127/An-iterative-method.
}
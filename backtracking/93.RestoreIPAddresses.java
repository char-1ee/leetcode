package backtracking;

import java.util.*;

class Solution {

    /** brute force due to limited length */
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        int n = s.length(); // 4 <= n <= 12
        if (n < 4 || n > 12)
            return res;

        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                    for (int d = 1; d <= 3; d++) {
                        if (a + b + c + d == n) {
                            int A = Integer.parseInt(s.substring(0, a));
                            int B = Integer.parseInt(s.substring(a, a + b));
                            int C = Integer.parseInt(s.substring(a + b, a + b + c));
                            int D = Integer.parseInt(s.substring(a + b + c));

                            if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                                String str = String.valueOf(A) + '.' + String.valueOf(B) + '.' + String.valueOf(C) + '.'
                                        + String.valueOf(D);
                                if (str.length() == n + 3) // check no leading 0s
                                    res.add(str);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

    /** Recursion */
    private List<String> res = new ArrayList<>();

    public List<String> restoreIpAddresses2(String s) {
        helper(s, 4, "");
        return res;
    }

    private void helper(String s, int k, String out) { // k stands for how many numbers left to be divided out from
                                                       // string
        if (k == 0 && s.isEmpty()) {
            res.add(out);
        }
        for (int i = 1; i <= 3; i++) {
            if (s.length() >= i && isValid(s.substring(0, i))) {
                if (k == 1)
                    helper(s.substring(i), k - 1, out + s.substring(0, i));
                else
                    helper(s.substring(i), k - 1, out + s.substring(0, i) + '.');
            }
        }
    }

    private boolean isValid(String s) {
        if (s.isEmpty() || s.length() > 3 || (s.length() > 1 && s.charAt(0) == '0'))
            return false;
        int x = Integer.parseInt(s);
        return x <= 255 && x >= 0;
    }
}

/** TODO: review Backtraking */
class Solution2 {

    private List<String> res = new ArrayList<>();
    private LinkedList<String> sub = new LinkedList<>();

    public List<String> restoreIpAddresses(String s) {
        int n = s.length();
        if (n < 4 || n > 12)
            return res;
        backtrack(s, 0, 4);
        return res;
    }

    private void backtrack(String s, int idx, int cnt) {
        if (idx == s.length() && cnt == 0) {
            res.add(String.join(".", sub));
            return;
        }
        for (int i = idx; i < idx + 3; i++) {
            if (i > s.length())
                break;
            if (cnt * 3 + i < s.length())
                continue;
            String str = (i + 1 < s.length()) ? s.substring(idx, i + 1) : s.substring(idx);
            if (isValid(str)) {
                sub.add(str);
                backtrack(s, i + 1, cnt - 1);
                sub.removeLast();
            }
        }
    }

    private boolean isValid(String s) {
        if (s.isEmpty() || s.length() > 3 || (s.length() > 1 && s.charAt(0) == '0'))
            return false;
        int x = Integer.parseInt(s);
        return x <= 255 && x >= 0;
    }

}
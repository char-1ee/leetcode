class Solution {  
    /** Iterative */
    public String countAndSay1(int n) {
        String res = "1";
        if (n < 2) return res;
        while (--n > 0) {
            String tmp = "";
            for (int i = 0; i < res.length(); i++) {
                int cnt = 1;                
                while (i < res.length() - 1 && res.charAt(i) == res.charAt(i + 1)) {
                    cnt++;
                    i++;
                }              
                tmp += Integer.toString(cnt) + res.charAt(i);
            }
            res = tmp;
        }
        return res;
    }

    /** Recursive */
    public String countAndSay(int n) {
        if (n == 1) return "1";
        String res = "", s = countAndSay(n - 1);
        int cnt = 1, sz = s.length();
        for (int i = 1; i < sz; i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                cnt++;
            } else {
                res += Integer.toString(cnt) + s.charAt(i-1); 
                cnt = 1;
            }
        }
        res += Integer.toString(cnt) + s.charAt(sz - 1);
        return res;
    }
}
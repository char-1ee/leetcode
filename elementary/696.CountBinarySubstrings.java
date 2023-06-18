package elementary;

class Solution {
    /** Group by character */
    public int countBinarySubstrings(String s) {
        int n = s.length(), k = 0, res = 0;
        int[] groups = new int[n];
        groups[0] = 1;
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) != s.charAt(i-1)) {
                groups[++k] = 1;
            } else {
                groups[k]++;
            }
        }
        for (int i = 1; i <=k; i++) {
            res += Math.min(groups[i], groups[i-1]);
        }
        return res;  
    }

    /** Linear scan */
    public int countBinarySubstrings2(String s) {
        int curr = 1, prev = 0, res = 0;
        for (int i = 1; i < s.length(); i++) 
        {
            if (s.charAt(i) == s.charAt(i - 1)) curr++;
            else {
                res += Math.min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }
        return res + Math.min(curr, prev);
    } 
}
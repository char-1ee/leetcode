class Solution {
    /** Reflection to array */
    public int minSteps(String s, String t) {
        int n = s.length(), cnt = 0;
        int[] ss = new int[26];
        int[] tt = new int[26];
        for (int i = 0; i < n; i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            ss[c1 - 'a']++;
            tt[c2 - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            if (tt[j] < ss[j])
                cnt += ss[j] - tt[j];
        }
        return cnt;
    }

    /** Optimized */
    public int minSteps2(String s, String t) {
        int[] ss = new int[26];
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            ++ss[s.charAt(i) - 'a'];
        }
        for (int j = 0; j < s.length(); j++) {
            char c = t.charAt(j);
            if (ss[c - 'a'] == 0)
                res++;
            else 
                ss[c - 'a']--;
        }
        return res;
    }
}
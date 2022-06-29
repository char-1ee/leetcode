package resursion_dp;

class Solution {
    public int minTimeToType(String word) {
        int len = word.length();
        int res = 0;
        char c = 'a';
        for (int i = 0; i < len; i++) {
            char c2 = word.charAt(i);
            int dist = Math.abs(c2 - c);
            res += Math.min(dist, 26 - dist);
            c = c2;
        }
        return res + len;
    }
}
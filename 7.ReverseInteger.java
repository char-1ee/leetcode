class Solution {
    public int reverse(int x) {
        int res = 0;
        while (x != 0){
            /*
             * check overflow/underflow MUST BEFORE multiplying 10 to res,
             * since the ovreflow is caused after multipling 10 
             */
            if (Math.abs(res) > Integer.MAX_VALUE / 10) return 0; 
     
            // pop = x % 10;
            // x /= 10;
            // temp = rev * 10 + pop;
            // rev = temp;
            res = x % 10 + res * 10; // simplifying
            x /= 10;
        }
        return res;
    }

    /**
     * Solution given by Leetcode;
     */
    public int reverse2(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > Integer.MAX_VALUE/10 || (rev == Integer.MAX_VALUE / 10 && pop > 7)) return 0;
            if (rev < Integer.MIN_VALUE/10 || (rev == Integer.MIN_VALUE / 10 && pop < -8)) return 0;
            /* 
             * Assume rev > 0:
             * 1. If temp = rev * 10 + pop overflow, then it must be that rev >= Integer.MAX_VALUE / 10;
             * 2. If rev > Integer.MAX_VALUE / 10, then temp = rev * 10 + pop is guaranteed to overflow.
             * 3.when rev == Integer.MAX_VALUE / 10, temp = rev * 10 + pop will ovreflow iff pop > 7 (similar pop < -8). 
             */
            rev = rev * 10 + pop;
        }
        return rev;
    }
}

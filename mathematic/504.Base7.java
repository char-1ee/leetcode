package mathematic;
class Solution {
    public String convertToBase7(int num) {
        if (num == 0) return "0";
        int sign = 1; 
        int res = 0;
        if (num < 0) {
            sign = -1;
            num = -num;
        }
        for (int i = 1; num > 0; i *= 10) {
            int rem = num % 7;
            num /= 7;
            res += rem * i;
        }
        
        return Integer.toString(res*sign);
        // return String.valueOf(res*sign);
    }

    /** String concatenation */
    public String convertToBase72(int num) {
        if (num == 0) return "0";
        String res = new String("");
        Boolean sign = num > 0;
        num = Math.abs(num);
        while (num != 0) {
            res = Integer.toString(num % 7) + res;
            num /= 7;
        }
        return sign ? res : "-"+res;
    }
}
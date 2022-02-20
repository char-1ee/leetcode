package mathematic;

class Solution {
    public int myAtoi(String s) {
        int n = s.length();
        if (n == 0) return 0;
        char[] arr = s.toCharArray();
        int i, sign = 1, val;
        
        for (i = 0; i < n && arr[i] == ' '; i++) // check i<n  
            ;
        if (i < n && (arr[i] == '-' || arr[i] == '+')) { // check i<n
            sign = (arr[i++] == '-') ? -1 : 1;
        }
        for (val = 0; i < n && arr[i] <= '9' && arr[i] >= '0'; i++) { // check i<n
            if (val > (Integer.MAX_VALUE / 10) || (val == (Integer.MAX_VALUE / 10) && (arr[i] - '0') > 7))
                return (sign == -1) ? Integer.MIN_VALUE : Integer.MAX_VALUE;          
            val = val * 10 + (arr[i] - '0');
        }
        return sign * val;
    }
}

/**
 * Checking overflow: https://leetcode.com/problems/string-to-integer-atoi/discuss/1402936/JAVA-C%2B%2B-%3A-Simple-or-Pictorial-Explanation-or-32-bit-int-or-Easy
 * 
 * Integer.MAX_VALUE = 2147483647 (10 digits)
 * Integer.MIN_VALUE = -2147483648 (10 digits)
 * 
 * In 9 digits: 214748364 (9 digits)
 * There can be inputs larger than `long long`, so compare `val` with `INT_MAX/10` is a more realistic way
 * 
 */
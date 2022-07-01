package bit_manipulation;

import java.math.BigInteger;

class Solution {
    /** Bit-by-bit compiutation. */
    public String addBinary(String a, String b) {
        int n = a.length(), m = b.length();
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        for (int i = n - 1, j = m - 1; i >= 0 || j >= 0 || carry == 1; i--, j--) {
            if (i >= 0 && a.charAt(i) == '1')
                carry++;
            if (j >= 0 && b.charAt(j) == '1')
                carry++;
            if (carry % 2 == 1)
                sb.append('1');
            else
                sb.append('0');
            carry /= 2;
        }
        return sb.reverse().toString();
    }

    /** Bit manipulation: https://leetcode.com/problems/add-binary/solution/ */
    public String addBinary2(String a, String b) {
        BigInteger x = new BigInteger(a, 2);
        BigInteger y = new BigInteger(b, 2);
        BigInteger zero = new BigInteger("0", 2);
        BigInteger carry, answer;
        while (y.compareTo(zero) != 0) {
            answer = x.xor(y);
            carry = x.and(y).shiftLeft(1);
            x = answer;
            y = carry;
        }
        return x.toString(2);
    }
}

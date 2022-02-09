class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i]++;
                return digits; // early return
            }
        }
        // case when 100..000
        int[] res = new int[n+1];
        res[0] = 1;
        return res;
    }

    public int[] plusOne2(int[] digits) {
        int carry = 1, n = digits.length;
        for (int i = n - 1; i >= 0; i--) {
            if (carry == 0) return digits; // when no more carry to add
            int sum = carry + digits[i];
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        int[] res = new int[n + 1];
        res[0] = 1;
        return carry == 0 ? digits : res; 
    }
}
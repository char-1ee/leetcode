package elementary.two_pointers;

class Solution {
    public void reverseString(char[] s) {
        int n = s.length;
        char temp;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            temp = s[j];
            s[j] = s[i];
            s[i] = temp;
        }
        // return StringBuilder(s).reverse().toString();
    }
}
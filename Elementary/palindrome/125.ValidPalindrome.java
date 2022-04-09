package elementary.panindrome;

class Solution {
    /** two pointers */
    public boolean isPalindrome(String s) {
        int n = s.length();
        // String s = s.toUpperCase(); // alternatively
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            while (i < j && !Character.isLetterOrDigit(s.charAt(i)))
                i++;
            while (i < j && !Character.isLetterOrDigit(s.charAt(j)))
                j--;
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j)))
                return false;
        }
        return true;
    }

    /** compar with reverse */
    public boolean isPalindrome2(String s) {
        StringBuilder sb = new StringBuilder("");
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c))
                sb.append(Character.toLowerCase(c));
        }
        String s1 = sb.toString();
        String s2 = sb.reverse().toString();
        return s1.equals(s2);
    }
}

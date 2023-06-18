class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
    
    bool isPalindrome(string s, int left, int right) {
        for (int i = left, j = right; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
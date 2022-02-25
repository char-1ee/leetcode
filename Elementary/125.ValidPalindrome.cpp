class Solution {
public:
    // two-pointers
    bool isPalindrome(string s) {
        string new_s = "";
        for (char c : s) {
            if (isalnum(c))
                new_s += tolower(c);
        }
        if (new_s.size() < 2) return true;
        for (int i = 0, j = new_s.size() - 1; i < j; i++, j--) {
            if (new_s[i] != new_s[j]) return false;
        }
        return true;
    }

    // in-place
    bool isPalindrome2(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !isalnum(s[i]))
                i++;
            while (i < j && !isalnum(s[j]))
                j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};
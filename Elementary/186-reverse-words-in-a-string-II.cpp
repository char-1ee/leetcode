class Solution {
   public:
    void reverseWords(vector<char> &s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0, j = 0; i < n && j < n;) {
            while (j < n && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1, j = i;
        }
        return;
    }
};
class Solution {
public:
    /** two pointer, two pass */
    string minRemoveToMakeValid(string s) {
        int left = 0;// left: how many opne '(' from left to curr index 
        int right = 0; // right:  how many opne ')' left in right of curr index
        string res;
        for (char c : s) {
            if (c == ')') right++;
        }
        for (char c : s) {
            if (c == '(') {
                if (left == right) continue;
                left++;
            } else if (c == ')') {
                right--;
                if (left == 0) continue;
                left--;
            }
            res += c;
        }
        return res;
    }
};
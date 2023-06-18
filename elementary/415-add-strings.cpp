class Solution {
public:
    string addStrings(string a, string b) {
        int n = a.length(), m = b.length();
        string res = "";
        int carry = 0;
        for (int i = n - 1, j = m - 1; i >= 0 || j >= 0;) {
            int c1 = (i >= 0) ? a[i--] - '0' : 0;
            int c2 = (j >= 0) ? b[j--] - '0' : 0;
            int sum = carry + c1 + c2;
            int digit = sum % 10;
            carry = sum / 10;
            res = to_string(digit) + res;
        }
        if (carry > 0)
            res = to_string(carry) + res;
        return res;
    }
};
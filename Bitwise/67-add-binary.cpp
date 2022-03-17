class Solution {
public:
    // general solution
    string addBinary(string a, string b) {
        string res = "";
        int n = a.size(), m = b.size();
        int carry = 0;
        for (int i = n-1, j = m-1; i >= 0 || j >= 0 || carry; i--, j--) {
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;
            int sum = carry + x + y;
            res += to_string(sum % 2);
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // official solution
     string addBinary2(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            int x = m >= 0 ? a[m--] - '0' : 0;
            int y = n >= 0 ? b[n--] - '0' : 0;
            int sum = x + y + carry;
            res = to_string(sum % 2) + res; // order of append new char
            carry = sum / 2 ;
        }
        return carry == 1 ? "1" + res : res;
    }
};
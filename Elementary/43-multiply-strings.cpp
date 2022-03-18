class Solution {
public:

    // naive methods
    string multiply(string num1, string num2) { 
        if (num1 == "0" || num2 == "0")
            return "0";
        int n = num1.size(), m = num2.size(); // n >=m
        if (n < m) return multiply(num2, num1);
        string res = "";
        for (int i = m - 1, cnt = 0; i >= 0; i--, cnt++) {
            int x = num2[i] - '0';
            string curr = multiply_single(num1, x) + string(cnt, '0');
            res = add_string(curr, res);
        }
        return res;
    }
    
    string multiply_single(string a, int x) {
        string res = "";
        int carry = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            int product = carry + (a[i] - '0') * x;
            int digit = product % 10;
            carry = product / 10;
            res = to_string(digit) + res;
        }
        if (carry > 0) res = to_string(carry) + res;
        return res;
    }
    
    string add_string(string a, string b) {
        int n = a.length(), m = b.length();
        string res = "";
        int carry = 0;
        for (int i = n - 1, j = m - 1; i >= 0 || j >= 0; i--, j--) {
            int c1 = (i >= 0) ? a[i] - '0' : 0;
            int c2 = (j >= 0) ? b[j] - '0' : 0;
            int sum = carry + c1 + c2;
            int digit = sum % 10;
            carry = sum / 10;
            res = to_string(digit) + res;
        }
        if (carry > 0)
            res = to_string(carry) + res;
        return res;
    }

    // great simplify
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        
        string res = "";
        int n = num1.length(), m = num2.length();

        // length of product of a and b cannot exceed n+m
        vector<int> vals(m + n);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');

                // nums[i]*num2[j] 's result is added to index (i+j) and (i+j+1)
                int p1 = i + j, p2 = i + j + 1;
                
                int sum = product + vals[p2];
                vals[p1] += sum / 10;
                vals[p2] = sum % 10;
            }
        }
        for (int val : vals) {
            // edge case: leading zeros are ignored but in-line zeros cannot be ignored
            if (!res.empty() || val != 0)
                res.push_back(val + '0');
        }
        return res;
    }
};
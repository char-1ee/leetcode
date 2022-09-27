class Solution {
public:
    string baseNeg2(int n) {
        string res = "";
        while (n) {
            string digit = to_string(n & 0x1);
            res = digit + res;
            n = -(n >> 1);
        }
        return res == "" ? "0" : res;
    }
};
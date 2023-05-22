class Solution {
public:
    bool confusingNumber(int n) {
        string s = to_string(n);
        string ss = "";
        for (auto c : s) {
            if (c == '2' || c == '3' || c == '4' || c == '5' || c == '7') return false;
            if (c == '6' || c == '9') {
                c =  c == '6' ? '9' : '6';
            }
            ss = c + ss;
        }
        return s != ss;
    }
};
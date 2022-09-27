class Solution {
public:
    // we noticed that given a and b are ensured to have a solution
    // 1. a == b. abababababab...
    // 2. a != b
    //   2.1. a == 0 || b == 0. just return
    //   2.2. a < b. bbabbabba...
    //   2.3. a > b. aabaabaab... (trend to be a == b)
    string strWithout3a3b(int a, int b) {
        if (a == 0) return string(b, 'b');
        if (b == 0) return string(a, 'a');
        else if (a == b) return "ab" + strWithout3a3b(a - 1, b - 1);
        else if (a < b) return "bba" + strWithout3a3b(a - 1, b - 2);
        else return "aab" + strWithout3a3b(a - 2, b - 1);
    }
};
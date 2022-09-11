class Solution {
public:
    /** property of Catalan Number */
    int numTrees(int n) {
        long res = 1; // avoid stackoverflow
        for (int i = n + 1; i <= 2 * n; ++i) {
            res = res * i / (i - n);
        }
        return res / (n + 1);
    }
};
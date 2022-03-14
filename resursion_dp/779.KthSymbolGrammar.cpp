class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        if (k % 2 == 0) return (kthGrammar(n - 1, k / 2) == 0) ? 1 : 0;
        return kthGrammar(n - 1, (k+1) / 2);
    }

    /** Bitwise */
    int kthGrammar2(int n, int k) {
        if (n == 1) return 0;
        // (~k & 1) to check the (1-index) position of k
        return (~k & 1) ^ kthGrammar2(n - 1, (k + 1) / 2);
    }
};
package bit_manipulation;

class Solution {
    int numComplement(int num) {
        int cnt = 0;
        int tmp = 0;
        while (tmp < num) {
            tmp += Math.pow(2, cnt);
            cnt++;
        }
        return tmp - num;  
    }

    /** Alternative */
    int numComplement2(int num) {
        int n = 0;
        while (n < num) {
            n = (n << 1) | 1;
        }
        return n - num;
    }
}
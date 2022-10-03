/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if (n < 1) return 0;
        
        int cnt, sum = 0;
        char buf4[4]; 
        char *pBuf = buf;
        
        do {
            cnt = read4(buf4);
            memcpy(pBuf, buf4, sizeof(buf4));
            pBuf += cnt;
            sum += cnt;
        } while (cnt == 4);
                
        return min(sum, n);
    }
};
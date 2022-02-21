class Solution {
    /** Backwards (TLE)  */
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) 
                return true;
            if (tx > ty) 
                tx -= ty;
            else
                ty -= tx;
        }
        return false;
    }

    /** Backwards with Modulo */
    public boolean reachingPoints2(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx > ty) {
                if (ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            } 
            else { 
                if (tx == sx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        return tx == sx && ty == sy;
    }
}
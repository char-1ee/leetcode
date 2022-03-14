class Solution {
    bool isSquare(int n) {
        int i = (int)sqrt(n);
        return i * i == n;
    }
    
public:

    /** 
     * Legendre's three-square theorem 
     * Legendre's four-square theorem 
     * Refer to https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
     */
    int numSquares1(int n) {
        // if n a prefect sqaure, return 1
        if (isSquare(n)) return 1;
        
        // if n is $4^a*(8b+7)$, return 4
        int tmp = n;
        while (tmp % 4 == 0) {
            tmp /= 4;
        }
        if (tmp % 8 == 7) return 4;
        
        // if n is composed of 2 perfect squares
        for (int i = 1; i * i < n; ++i) {
            if (isSquare(n - i*i))
                return 2;
        }
        
        // otherwise, n is composed of 3 perfect squares
        return 3;
    }

    /** BFS */
    int numSquares2(int n) {
        queue<int> q{{n}};
        unordered_set<int> set;
        int level = 0;
        
        while (!q.empty()) {
            ++level;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int t = q.front(); q.pop();
                if (set.count(t) == 1) continue;
                else set.insert(t);
                for (int j = 1; j * j <= t; ++j) {
                    if (t - (j*j) == 0) return level;
                    q.push(t - j*j);
                }
            }
        }
        return 4;
    }
};
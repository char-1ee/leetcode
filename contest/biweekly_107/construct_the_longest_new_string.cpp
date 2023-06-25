#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[51][51][51][4] = {0}; // #x, #y, #z, last added char

    int f(int x, int y, int z, int prev) {
        if (dp[x][y][z][prev] != 0) return dp[x][y][z][prev];
        int size = 0;
        if (x > 0 && prev != 1) size = max(size, 2 + f(x - 1, y, z, 1)); // add x
        if (y > 0 && prev <= 1) size = max(size, 2 + f(x, y - 1, z, 2)); // add y
        if (z > 0 && prev != 1) size = max(size, 2 + f(x, y, z - 1, 3)); // add z
        dp[x][y][z][prev] = size;
        return size;
    }

    int longestString(int x, int y, int z) {
        return f(x, y, z, 0);
    }
};

// x:y
// z,y:z no x
// z,y:x no x
// prev: x: 1, y: 2, z:3
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isRobotBounded(string s) {
        int n = s.length(), x = 0, y = 0, dir = 0;
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto c : s) {
            if (c == 'G') {
                x += dirs[dir][0];
                y += dirs[dir][1];
            } else if (c == 'L') {
                dir = (dir - 1 + 4) % 4;
            } else {
                dir = (dir + 1) % 4;
            }
        }
        return dir > 0 || (x == 0 && y == 0);
    }
};
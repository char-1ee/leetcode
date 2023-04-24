#include <bits/stdc++.h>

class Solution {
   public:
    int findDelayedArrivalTime(int x, int y) { return (x + y + 24) % 24; }
};
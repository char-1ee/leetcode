#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    static int countBits(int x) {
        int res = 0;
        while (x > 0) {
            x &= (x - 1);
            x >>= 1;
        }
        return res;
    }

    static bool comp(const int a, const int b) {
        int x = countBits(a), y = countBits(b);
        if (x == y)
            return a < b;
        else
            return x < y;
    }

    vector<int> sortByBits(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};
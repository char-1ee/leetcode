#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // sqrt(x) = pow(e, 0.5 * ln(x))
    int sqrt(int x) {
        if (x < 2) return x;
        int left = (int) exp(0.5 * log(x));
        int right = left + 1;
        return right * right > x ? left : right;
    }

    // binary search
    int sqrt2(int x) {
        if (x < 2) return x;
        int left = 0, right = x / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long num = (long)mid * mid;
            if (num == x) return mid;
            else if (num > x) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};
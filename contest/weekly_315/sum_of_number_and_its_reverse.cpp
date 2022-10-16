#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if (num == 0) return true;
        int mid = num / 2;
        for (int i = mid; i < num; i++) {
            string s = to_string(i);
            reverse(s.begin(), s.end());
            if (stoi(s) + i == num)
                return true;
        }
        return false;
    }
};
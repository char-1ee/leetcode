#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // greedy: backward
    bool canJumpGreedy1(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return true;
        int pos = n - 1;
        for (int i = pos - 1; i >= 0; i--) {
            if (nums[i] + i >= pos) {
                pos = i;
                if (pos == 0) return true;
            }
        }
        return false;
    }

    // greedy: forward
    bool canJumpGreedy2(vector<int> &nums) {
        int n = nums.size();
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (i > pos || pos >= n - 1) break;
            pos = max(pos, i + nums[i]);
        }
        return pos >= n - 1;
    }
};
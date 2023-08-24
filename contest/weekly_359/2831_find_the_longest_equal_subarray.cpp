#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestEqualSubarray(vector<int> &nums, int k) {
        int n = nums.size(), res = 0;
        vector<vector<int>> A(n + 1);
        for (int i = 0; i < n; i++) {
            A[nums[i]].push_back(i);
        }

        for (int u = 1; u <= n; u++) {
            auto &idx = A[u];
            for (int i = 0, j = 0; i < idx.size(); i++) {
                while ((idx[i] - idx[j] + 1) - (i - j + 1) > k) {
                    j++;
                }
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};

// 2 thinking points:
// 1. 2 pointers/sliding windows to find result
// 2. nums[i] is restricted in [1, n], which means we can build mapping from
// nums[i] to its appearence of indexes.
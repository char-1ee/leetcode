#include <bits/stdc++.h>
using namespace std;

// Typical `find maximum min value` problem -> binary search
class Solution {
   public:
    // Check whether there are k items that satisfy their min distance is mid(x)
    bool check(vector<int> &A, int x, int k) {
        int prev = A[0], cnt = 1;
        for (auto num : A) {
            if (num >= prev + x) {
                cnt++;
                prev = num;
            }
        }
        return cnt >= k;
    }

    int maximumTastiness(vector<int> &price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int lo = 0, hi = price[n - 1] - price[0];
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check(price, mid, k)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
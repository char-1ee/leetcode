#include <bits/stdc++.h>
using namespace std;

// Min heap
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        for (long i = 1; i < n; i++) {
            long t = pq.top();
            pq.pop();
            // remove duplicates
            while (!pq.empty() && pq.top() == t)
                pq.pop();
            pq.push(t * 2);
            pq.push(t * 3);
            pq.push(t * 5);
        }
        return pq.top();
    }
};

// DP solution.
// We want to generate all ugly number in order. Initution tells we need traverse all ugly number we
// have to multiply 2, 3, 5 then get next ugly number. Then here we can think of DP, to maintain
// pointers of 3, which are to record the position of last ugly number that can produce next ugly
// number. For example, say we have {1, 2, 3 ... 15}, to find next ugly number. Without DP, we need
// traverse 1...15 and test product of each of them with 2, 3, 5 is next ugly number or not.
// With DP, we can know 15 is generated by min(2*7, 3*5, 5*3), then next must be min(2*8, 3*6, 5*4) = 16.
class Solution2 {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++) {
            int mn = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
            dp[i] = mn;
            if (mn == dp[p2] * 2) p2++;
            if (mn == dp[p3] * 3) p3++;
            if (mn == dp[p5] * 5) p5++;
        }
        return dp[n - 1];
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxCount(vector<int> &banned, int n, int maxSum) {
        int sum = 0, cnt = 0;
        set<int> st(banned.begin(), banned.end());
        for (int i = 1; i <= n; i++) {
            if (st.count(i)) continue;
            sum += i;
            if (sum > maxSum)
                return cnt;
            else
                cnt++;
        }
        return cnt;
    }
};
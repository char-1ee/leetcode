
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        int res = 0;
        for (int i = 1; st.size() < n; i++) {
            if (!st.count(k - i)) {
                st.insert(i);
                res += i;
            }
        }
        return res;
    }
};
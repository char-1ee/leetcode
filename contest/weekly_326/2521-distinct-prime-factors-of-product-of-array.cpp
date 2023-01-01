#include <bits/stdc++.h>
using namespace std;

// Template of divide prime factor
class Solution {
   public:
    int distinctPrimeFactors(vector<int> &nums) {
        unordered_set<int> st;
        for (auto x : nums) {
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    st.insert(i);
                    while (x % i == 0) x /= i;
                }
            }
            if (x > 1) st.insert(x);
        }
        return st.size();
    }
};
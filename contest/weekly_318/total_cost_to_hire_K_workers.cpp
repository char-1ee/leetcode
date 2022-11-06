#include <bits/stdc++.h>
using namespace std;

// TLE solution
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        long long res = 0;
        int cnt = 0;
        while (cnt < k) {
            if (costs.size() >= c) {
                auto t1 = min_element(costs.begin(), costs.begin() + c);
                auto t2 = min_element(costs.end() - c, costs.end());                    
                auto it = costs.begin();
                
                if (*t1 != *t2) {
                    it = *t1 < *t2 ? t1 : t2;                    
                } else { // ==
                    int idx = min(t1 - costs.begin(), t2 - costs.begin());
                    it = costs.begin() + idx; 
                }
                res += (long long)*it;
                costs.erase(it);
                
            } else {
                auto it = min_element(costs.begin(), costs.end());
                res += (long long)*it;
                costs.erase(it);
            }
            cnt++;
        }
        return res;
    }
};
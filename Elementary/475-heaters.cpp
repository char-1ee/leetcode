#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        vector<int> res(n, INT_MAX);
        for (int i = 0, j = 0; i < n && j < m; ) {
            if (houses[i] <= heaters[j]) {
                res[i] = heaters[j] - houses[i];
                i++;
            } else {
                j++;
            }
        }
        
        for (int i = n - 1, j = m -1; i >= 0 &&  j >= 0; ) {
            if (houses[i] >= heaters[j]) {
                res[i] = min(res[i], houses[i] - heaters[j]);
                i--;
            } else {
                j--;
            }
        }
        return *max_element(res.begin(), res.end());
    }
};
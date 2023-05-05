#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        priority_queue<pair<int, int>> q1; // max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            q2; // min heap
        for (int i = 0; i < m; i++) {
            q2.push({arrays[i][0], i});
            q1.push({arrays[i].back(), i});
        }
        auto t1 = q1.top();
        q1.pop();
        auto t2 = q2.top();
        q2.pop();

        if (t1.second == t2.second) {
            return max(t1.first - q2.top().first, q1.top().first - t2.first);
        } else {
            return t1.first - t2.first;
        }
    }
};
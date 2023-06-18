#include <bits/stdc++.h>
using namespace std;

// Bucket sort
// time O(max(1001, N)), space O(1001)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> buckets(1001, 0);
        
        for (auto trip : trips) {
            buckets[trip[1]] += trip[0];
            buckets[trip[2]] -= trip[0];
        }
        
        // simulate change of capacity
        int curr = 0;
        for (int num : buckets) {
            curr += num;
            if (curr > capacity) return false;
        }
        return true;
    }
};

// Interval problems: sort start points and end points respectively,
// then organize them on a new timeline
// time O(n), space O(n)
class Solution2 {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<vector<int>> data;
        
        for (auto trip : trips) {
            data.push_back({trip[1], trip[0]});
            data.push_back({trip[2], -trip[0]});
        }
        sort(data.begin(), data.end());
        
        int curr = 0;
        for (auto a : data) {
            curr += a[1];
            if (curr > capacity) {
                return false;
            }
        }
        return true;
    }
};
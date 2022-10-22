#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> map;
        for (auto n : arr) {
            map[n]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& e : map) {
            pq.push(e.second);
        }
        while (k > 0) {
            k -= pq.top();
            if (k >= 0) {
                pq.pop();
            }
        }
        return pq.size();
    }
};
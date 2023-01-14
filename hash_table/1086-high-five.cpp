#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> heap;

class Solution {
   public:
    vector<vector<int>> highFive(vector<vector<int>> &items) {
        int n = items.size();
        vector<vector<int>> res;
        unordered_map<int, heap> st;

        for (auto item : items) {
            auto &pq = st[item[0]];
            pq.push(item[1]);
            if (pq.size() > 5) pq.pop();
        }

        for (auto t : st) {
            int ave = 0;
            while (!t.second.empty()) {
                ave += t.second.top();
                t.second.pop();
            }
            vector<int> s(2);
            s[0] = t.first;
            s[1] = ave / 5;
            res.emplace_back(s);
        }

        sort(res.begin(), res.end());
        return res;
    }
};
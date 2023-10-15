#include <bits/stdc++.h>
using namespace std;

// Simulation
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cycle = n + 1, res = 0;
        unordered_map<int, int> st;
        for (auto task : tasks) {
            st[task]++;
        }
        priority_queue<pair<int, int>> pq; // can use pq<int> here
        for (auto& [k, v] : st) {
            pq.push({v, k});
        }

        while (!pq.empty()) {
            int cnt = 0;
            vector<pair<int, int>> t;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    t.push_back(pq.top());
                    pq.pop();
                    cnt++;
                }
            }
            for (auto p : t) {
                int freq = p.first - 1;
                if (freq > 0) {
                    pq.push({freq, p.second});
                }
            }
            res += pq.empty() ? cnt : cycle;
        }
        return res;
    }
};

// Calculation
class Solution_2 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx = 0, mxCnt = 0;
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            ++cnt[task - 'A'];
            if (mx == cnt[task - 'A']) {
                ++mxCnt;
            } else if (mx < cnt[task - 'A']) {
                mx = cnt[task - 'A'];
                mxCnt = 1;
            }
        }
        int partCnt = mx - 1;
        int partLen = n - (mxCnt - 1);
        int emptySlots = partCnt * partLen;
        int taskLeft = tasks.size() - mx * mxCnt;
        int idles = max(0, emptySlots - taskLeft);
        return tasks.size() + idles;
    }
};
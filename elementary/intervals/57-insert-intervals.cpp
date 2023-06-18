#include <bits/stdc++.h>
using namespace std;

// insert -> sort -> merge
// time O(nlogn), space O(n)
class Solution1 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        merge(intervals);
        return intervals;
    }

    void merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) return;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> stack{intervals[0]};

        for (int i = 1; i < n; i++) {
            auto prev = stack.back();
            auto curr = intervals[i];
            if (curr[0] > prev[1]) { // non-overlap
                stack.push_back(curr);
            } else { // overlap: curr[0] < prev[1]
                stack.back()[1] = max(prev[1], curr[1]);
            }
        }
        intervals = stack;
        return;
    }
};

// Greedy. iteration with merges
// time O(n), space O(n)
class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> stack;
        int i = 0;

        // phrase 1
        // push intervals smaller than newInterval
        while (i < n && newInterval[0] > intervals[i][0]) {
            stack.push_back(intervals[i++]);
        }

        // phrase 2
        // merge stack.back() with newInterval
        if (stack.empty() || stack.back()[1] < newInterval[0]) {
            stack.push_back(newInterval);
        } else {
            // auto tmp = stack.back(); stack.pop_back();
            // tmp[1] = max(tmp[1], newInterval[1]);
            // stack.push_back(tmp);
            stack.back()[1] = max(stack.back()[1], newInterval[1]);
        }

        // phrase 3
        // push rest interval and to see whether need merge with stack.back()
        while (i < n) {
            if (stack.back()[1] < intervals[i][0]) {
                stack.push_back(intervals[i]);
            } else {
                // auto tmp = stack.back(); stack.pop_back();
                // tmp[1] = max(tmp[1], intervals[i][1]);
                // stack.push_back(tmp);
                stack.back()[1] = max(stack.back()[1], intervals[i][1]);
            }
            i++;
        }

        return stack;
    }
};
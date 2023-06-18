#include <bits/stdc++.h>
using namespace std;

// sort start points and end points seperately
class MergeIntervals {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts, ends;

        for (auto interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        sort(starts.begin(),starts.end());
        sort(ends.begin(), ends.end());

        // j: points to start of a new interval
        // i: points to end of a new interval
        for (int i = 0, j = 0; i < n; ++i) {
            
            // notation: || has its logical precedure
            if (i == n - 1 || starts[i + 1] > ends[i]) {
                res.push_back({starts[j], ends[i]});
                j = i + 1;
            }
        }
        return res;
    }
};

// iteration
class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) return intervals;

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

        return stack;
    }
};
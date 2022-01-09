class MergeIntervals {
public: 
    
    // sort start points and end points seperately
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts, ends;

        for (int i = 0; i < n; i++) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }

        sort(starts.begin(), ends.end());
        sort(starts.begin(), ends.end());

        for (int i = 0, j = 0; i < n; ++i) {

            // notation: || has its logical precedure
            if (i == n - 1 || starts[i + 1] > ends[i]) {
                res.push_back({starts[j], ends[i]});
                j = i + 1;
            }
        }
        return res;
    }


    // normal iterations
    vector<vector<int>> merge2(vector<vector<int>> &intervals) {
        if (intervals.size() < 2) return intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

        vector<vector<int>> res{intervals[0]};

        for (int i = 0; i < n; i++) {
            if (intervals[i][0] < res.back()[1]) {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            } else {
                res.push_back({intervals[i][0], res.back()[1]});
            }
        }
        return res;
    }
}
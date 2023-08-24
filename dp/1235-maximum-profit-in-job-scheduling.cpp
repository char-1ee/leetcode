#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                      vector<int> &profit) {
        int n = startTime.size(), maxProfit = 0;
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        // pq {currChainEndTime: currChainProfit}, minHeap for endTime
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        for (auto job : jobs) {
            int s = job[0], e = job[1], p = job[2];
            while (!pq.empty() && pq.top()[0] <= s) {
                maxProfit = max(maxProfit, pq.top()[1]);
                pq.pop();
            }
            pq.push({e, maxProfit + p});  // if no non-conflicting job is
                                          // present maxProfit will be 0
        }

        while (!pq.empty()) {
            maxProfit = max(maxProfit, pq.top()[1]);
            pq.pop();
        }
        return maxProfit;
    }
};

// There are two key observations to make:
// 1. For each job we want to find all chains that end before the current job's
// start time.
// 2. Since the jobs are sorted according to start time if a chain does not
// conflict with the current job, then it will also not conflict with any future
// job.
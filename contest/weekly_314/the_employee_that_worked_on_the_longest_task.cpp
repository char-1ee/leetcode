#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int id = logs[0][0], time = logs[0][1];

        for (int i = 1; i < logs.size(); i++) {
            int currTime = logs[i][1] - logs[i - 1][1];
            if (currTime > time || currTime == time && logs[i][0] < id) {
                time = currTime;
                id = logs[i][0];
            }
        }
        return id;
    }
};
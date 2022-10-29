#include <bits/stdc++.h>
using namespace std;

// Solution 1: weighted median
// {nums [1, 2, 3], cost [2, 3, 1]} equals to [1, 1, 2, 2, 2, 3]
// Time O(nlogn), Space O(n)
class Solution1 {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long totalCost = 0;
        vector<pair<int, int>> w;
        for (int i = 0; i < n; i++) {
            w.push_back({nums[i], cost[i]});
            totalCost += cost[i];
        }

        sort(w.begin(), w.end()); // sort by pair.first by default

        int median = 0; // weighted median
        long long currCost = 0;
        for (auto t : w) {
            currCost += t.second;
            if (currCost > totalCost / 2) {
                median = t.first;
                break;
            }
        }

        // calculate cost based on median
        long long minCost = 0;
        for (int i = 0; i < n; i++) {
            minCost += (long long)abs(median - nums[i]) * cost[i];
        }
        return minCost;
    }
};

// Solution 2: Binary search
// The cost proved to be a convex function, which we can compare f(i) and f(i + 1) to find the min
// point in the convex function.
// Time O(nloga), Space O(n)
class Solution2 {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long left = 0, right = 1e6;
        long long res = 0; // final min cost

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long y1 = findCost(nums, cost, mid);
            long long y2 = findCost(nums, cost, mid + 1);

            res = min(y1, y2);

            if (y1 < y2) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }

    // Calculate the cost based on median `mid`
    long long findCost(vector<int>& nums, vector<int>& cost, int mid) {
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += (long long)cost[i] * abs(nums[i] - mid);
        }
        return res;
    }
};
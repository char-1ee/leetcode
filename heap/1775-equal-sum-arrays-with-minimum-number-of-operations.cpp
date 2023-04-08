#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), cnt = 0;
        if (6 * n < m || 6 * m < n) return -1;

        int sum1 = 0, sum2 = 0;
        for (auto num : nums1) sum1 += num;
        for (auto num : nums2) sum2 += num;
        if (sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }

        // min heap for nums1 (smaller)
        priority_queue<int, vector<int>, greater<int>> pq1(nums1.begin(), nums1.end());
        // max heap for nums2 (larger)
        priority_queue<int> pq2(nums2.begin(), nums2.end());
        int diff = sum2 - sum1;
        while (diff > 0) {
            cnt++;
            if (pq2.empty() || 6 - pq1.top() > pq2.top() - 1) {
                diff -= 6 - pq1.top();
                pq1.pop();
            } else {
                diff -= pq2.top() - 1;
                pq2.pop();
            }
        }
        return cnt;
    }
};

class Solution2 {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), cnt = 0;
        if (6 * n < m || 6 * m < n) return -1;

        int sum1 = 0, sum2 = 0;
        for (auto num : nums1) sum1 += num;
        for (auto num : nums2) sum2 += num;
        if (sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }

        priority_queue<int> pq;
        for (auto num : nums1) pq.push(6 - num);
        for (auto num : nums2) pq.push(num - 1);
        int diff = sum2 - sum1;
        if (diff == 0) return 0;
        while (!pq.empty()) {
            int t = pq.top();
            pq.pop();
            diff -= t;
            cnt++;
            if (diff <= 0) return cnt;
        }
        if (diff > 0) return -1; // not neccessary
        return cnt;
    }
};
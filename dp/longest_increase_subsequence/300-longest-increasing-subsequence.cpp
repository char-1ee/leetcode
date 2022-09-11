#include <bits/stdc++.h>
using namespace std;

// DP solution
// time O(n^2) space O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// Greedy approach
// time O(n^2) in worst cases, space O(n)
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v.emplace_back(nums[0]);
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > v[v.size() - 1]) {
                v.emplace_back(nums[i]);
            } else {
                int idx = 0; // index of last element that >= nums[i]
                while (nums[i] > v[idx]) {
                    idx++;
                }
                v[idx] = nums[i];
            }
        }
        return v.size();
    }
};

// Patience sorting:
// Greedy approach + Binary search
// time O(nlogn) space O(n)
class Solution3 {
public:
    // greedy approach
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v.emplace_back(nums[0]);
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > v[v.size() - 1]) {
                v.emplace_back(nums[i]);
            } else {
                int idx = bs(v, nums[i]);
                v[idx] = nums[i];
            }
        }
        return v.size();
    }
    
    int bs(vector<int> v, int num) {
        int lo = 0, hi = v.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) /2;
            if (v[mid] == num) {
                return mid;
            }
            else if (v[mid] < num) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return hi ;
    }
};
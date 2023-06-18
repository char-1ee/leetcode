#include <bits/stdc++.h>
using namespace std;

// Sliding window. Worst O(n^2), best O(n). 2 iteration but with nested iterations
class Solution1 {
public:
    inline int getDegree(unordered_map<int, int>& m) {
        int res = 0;
        for (auto& t : m) {
            res = max(res, t.second);
        }
        return res;
    }
    
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int degree = 1;
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
            degree = max(degree, m[num]);
        }

        int minL = n, l = 0, r = 0;
        unordered_map<int, int> mp;
        while (r < n) {
            int num = nums[r++];
            mp[num]++;
            while (getDegree(mp) == degree) {
                minL = min(minL, r - l );
                int tmp = nums[l++];
                mp[tmp]--;
            }
        }
        return minL;
    }
};

// Maintain first occurence and last occurence. Worst O(n*n/2), best O(n).
class Solution2 {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int degree = 1;
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
            degree = max(degree, m[num]);
        }
        vector<int> v;
        for (auto&t : m) {
            if (t.second == degree) {
                v.push_back(t.first);
            }
        }

        int minL = n;
        for (auto e : v) {
            int startIdx = find(nums.begin(), nums.end(), e) - nums.begin();
            int endIdx = n - 1 - (find(nums.rbegin(), nums.rend(), e) - nums.rbegin());
            minL = min(minL, endIdx - startIdx + 1);
        }
        return minL;
    }
};

// Map startIdx of each element. O(n). Only 1 iteration.
class Solution3 {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), degree = 1, res = n;    
        unordered_map<int, int> m, startIdxs;
        for (int i = 0; i <  n; i++) {
            m[nums[i]]++;
            if (!startIdxs.count(nums[i])) {
                startIdxs[nums[i]] = i;
            }
            if (m[nums[i]] == degree) {
                res = min(res, i - startIdxs[nums[i]] + 1);
            } else if (m[nums[i]] > degree) {
                res = i - startIdxs[nums[i]] + 1;
                degree = m[nums[i]];
            }
        }
        return res;
    }
};
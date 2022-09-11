#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0, maxLength = 0, n = nums.size();
        vector<int> len(n, 1); // length of increasing subsequence ends with i-index
        vector<int> cnt(n, 1); // cnt of increasing subsequence ends with i-index element 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) continue;
                
                if (len[i] == len[j] + 1) {
                    cnt[i] += cnt[j];
                }
                
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
            maxLength = max(maxLength, len[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (len[i] == maxLength) {
                res += cnt[i];
            }
        }
        return res;
    }
};
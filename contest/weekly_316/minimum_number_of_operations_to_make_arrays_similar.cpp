#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> odd1, odd2, even1, even2;

        // depart into even part and odd part:
        // because +2/-2 wont change parity of A[i]/A[j] (after one operation, odd to odd, even to even)
        // thus, we only need to count difference between elements with same index in sorted array.

        for (auto num : nums) {
            if (num % 2 == 0)
                even1.push_back(num);
            else
                odd1.push_back(num);
        }
        for (auto t : target) {
            if (t % 2 == 0)
                even2.push_back(t);
            else
                odd2.push_back(t);
        }

        long long res = 0;
        res += count(odd1, odd2);
        res += count(even1, even2);
        return res;
    }

    // noticed that there guranteed nums can be changed to target,
    // so we only need count increment or decrement operations
    long long count(vector<int>& v1, vector<int>& v2) {
        long long cnt = 0;
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] < v2[i]) cnt += (v2[i] - v1[i]) / 2;
        }
        return cnt;
    }
};
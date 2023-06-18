#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // i: last non-zero element; j: current element
        int i = 0, j = 0; 
        while (j < nums.size())
        {
            if (nums[j] != 0) {
                swap(nums[i++], nums[j]);
            }
            j++;
        }
    }
};
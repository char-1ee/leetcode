class Solution {
public:
    // binary search
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int left = j + 1, right = n, sum = nums[i] + nums[j]; 
                while (left < right) { // upper_bound
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) left = mid + 1;
                    else right = mid; // nums[mid] >= sum
                } 
                
                res += right - 1 - j;
            }
        }
        return res;
    }

    // binary search with memorization
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < n - 1 && nums[i] != 0; j++) {
                int left = k, right = n, sum = nums[i] + nums[j]; 
                while (left < right) { // upper_bound
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) left = mid + 1;
                    else right = mid; // nums[mid] >= sum
                } 
                k = right;
                res += k - 1 - j;
            }
        }
        return res;
    }
};
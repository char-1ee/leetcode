class Solution {
public:
    /** Binary Search */
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < nums[mid+1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }

    /** Linear iterative */
    int findPeakElement2(vector<int>& nums) {
        int n = nums.size();
        for (int i =1; i< n; i++) {
            if (nums[i] < nums[i - 1]) return i - 1;
        }
        return n - 1;
    }
};
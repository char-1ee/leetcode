class Solution {
public:
    // O(n) and O(n)
    int pivotIndex1(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> left(n, 0), right(n, 0);
        for (int i = 1, j = n - 2; i < n && j >= 0; ++i, --j) {
            left[i] = left[i - 1] + nums[i - 1];
            right[j] = right[j + 1] + nums[j + 1];
        } 
        for (int i = 0; i < n; ++i) {
            if (left[i] == right[i])
                return i;
        }
        return -1;
    }

    // O(n) and O(1)
    int pivotIndex2(vector<int>& nums) {
        int n = nums.size(), sum = 0, leftSum = 0;
        if (n == 1) return 0;
        for (int num : nums) sum += num;
        for (int i = 0; i < n; ++i) {
            if (leftSum == sum - leftSum - nums[i])
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        
        // To avoid there is INT_MIN in array:
        // For Java:
        // - declare `Integer` x1, x2, x3 to `null`
        // - or use Long.MIN_VALUE

        long x1 = LONG_MIN, x2 = LONG_MIN, x3 = LONG_MIN;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > x1) {
                x3 = x2;
                x2 = x1;
                x1 = nums[i];
            } else if (nums[i] > x2 && nums[i] < x1) {
                x3 = x2;
                x2 = nums[i];
            } else if (nums[i] < x2 && nums[i] > x3) {
                x3 = nums[i];
            } 
        }
        return (x3 == LONG_MIN || x3 == x2) ? x1 : x3;
    }
};
class Solution {
public:
    // O(n), O(1), two-pointers 
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.size() < 1) 
            return nums;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && (nums[i] & 0x1) == 0) {
                i++;
            }
            while (i < j && (nums[j] & 0x1) != 0) {
                j--;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
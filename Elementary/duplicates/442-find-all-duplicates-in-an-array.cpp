class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
                
        for (int num : nums) {
            int idx = abs(num);
            if (nums[idx - 1] < 0) {
                res.emplace_back(idx);
            } else {
                nums[idx - 1] *= -1;
            }
        }
        return res;
    }
};
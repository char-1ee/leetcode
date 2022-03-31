class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        backtrack(res, sub, candidates, target, 0);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums, int sum, int idx) {
        if (sum < 0) {
            return;
        } else if (sum == 0) {
            res.push_back(sub);
            return;
        } else {
            for (int i = idx; i < nums.size(); ++i) {
                if (i > idx && nums[i] == nums[i-1])
                    continue;
                sub.push_back(nums[i]);
                backtrack(res, sub, nums, sum - nums[i], i + 1);
                sub.pop_back();
            }
        }
    }
};
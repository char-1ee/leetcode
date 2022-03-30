class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(candidates.begin(), candidates.end()); // sorting
        backtrack(candidates, target, 0, sub, res);
        return res;
    }
    
    // use `target-nums[i]` to represent current state rather than using `sum` comparing with `target`
    void backtrack(vector<int>& nums, int target, int idx, vector<int>& sub, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            res.push_back(sub);
            return;
        } 
        
        for (int i = idx; i < nums.size(); ++i) {
            sub.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, sub, res); // recursion from same index i since elements can be reused
            sub.pop_back();
        }
    }
};
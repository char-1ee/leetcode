class Solution {
public:
    // backtracking
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        backtrack(nums, sub, res, 0);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& sub, vector<vector<int>>& res, int index) {
        res.push_back(sub);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i-1])
                continue;
            sub.push_back(nums[i]);
            backtrack(nums, sub, res, i + 1);
            sub.pop_back();
        }
    }

    // cascading
    vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());

        // 当处理到第一个2时，此时的子集合为 [], [1], [2], [1, 2]，而这时再处理第二个2时，
        // 如果在 [] 和 [1] 后直接加2会产生重复，所以只能在上一个循环生成的后两个子集合后面加2
        int n = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int start = (i > 0 && nums[i] == nums[i-1]) ? n : 0;
            n = res.size();
            for (int j = start; j < n; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
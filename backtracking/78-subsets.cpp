class Solution {
public:

    // Backtracking
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> list;
        backtrack(list, res, nums, 0);
        return res;
    }
    void backtrack(vector<int>& list, vector<vector<int>>& res, vector<int>& nums, int index) {
        
        // no need for a terminal condition, start > nums.length
        // due to property of subsets, if start > nums.length, return
        res.push_back(list);
        for (int i = index; i < nums.size(); ++i) {
            list.push_back(nums[i]);
            backtrack(list, res, nums, i+ 1);
            list.pop_back();
        }
    }

    // Casscading
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size(); // must fetch out the lenth, otherwise thread unsafty
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }

    
};
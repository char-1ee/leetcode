class Solution {
public:

    // Backtracking (differ from traditional backtrack, more like trees' recursion)
    // refer to https://www.cnblogs.com/TenosDoIt/p/3451902.html
    // the inserting order: 
    // [], [1], [1 2], [1 2 3], [1 3], [2], [2 3], [3]
    vector<vector<int>> subsets1(vector<int>& nums) {
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
            backtrack(list, res, nums, i + 1);
            list.pop_back();
        }
    }

    // Casscading
    vector<vector<int>> subsets2(vector<int>& nums) {
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

    // Lexicographic (Binary Sorted) Subsets
    vector<vector<int>> subsets3(vector<int>& nums) {
        vector<vector<int>> res;
        int max = 1 << nums.size();
        for (int i = 0; i < max; i++) {
            vector<int> num = mask(nums, i);
            res.push_back(num);
        }
        return res;
    }
    
    vector<int> mask(vector<int>& nums, int k) {
        vector<int> sub; 
        for (int idx = 0, i = k; i > 0; i >>= 1, idx++) {
            if (i & 1 == 1) {
                sub.push_back(nums[idx]);
            }
        }
        return sub;
    }
};
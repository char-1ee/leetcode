class Solution {
public:
    /** Brute force DFS */
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0; // result 
        bfs(nums, target, 0, res);
        return res;  
    }
    void bfs(vector<int>& nums, int target, int index, int& res) {
        if (index >= nums.size()) {
            if (target == 0) ++res;
            return;
        }
        bfs(nums, target - nums[index], index + 1, res);
        bfs(nums, target + nums[index], index + 1, res);
    }

    /** DFS with memorization */
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> memo(nums.size());
        return bfs(nums, target, 0, memo);
        
    }
    int dfs(vector<int>& nums, int sum, int index, vector<unordered_map<int, int>>& memo) {
        if (index == nums.size()) return sum == 0;
        if (memo[index].count(sum)) return memo[index][sum];
        
        int cnt1 = dfs(nums, sum - nums[index], index + 1, memo);
        int cnt2 = dfs(nums, sum + nums[index], index + 1, memo);
        return memo[index][sum] = cnt1 + cnt2;
    }
};
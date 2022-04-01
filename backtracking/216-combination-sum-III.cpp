class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sub;
        backtrack(res, sub, 1, n, k);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& sub, int idx, int sum, int k) {
        
        // efficient pruning
        if (sum < 0)
            return;
        
        if (sub.size() == k) {
            if (sum == 0) {
                res.push_back(sub);
            }
            return;
        }
        
        for (int i = idx; i < 10; i++) {
            sub.push_back(i);
            backtrack(res, sub, i+1, sum - i, k);
            sub.pop_back();
        }
    }
};
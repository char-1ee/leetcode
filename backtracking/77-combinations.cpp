class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sub;
        backtrack(res, sub, 1, n, k);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& sub, int idx, int n, int k) {
        if (sub.size() == k) {
            res.push_back(sub);
            return;
        }
        
        // prune trees: n - (sub.size() - k) + 1
        for (int i = idx; i <= n - (k - sub.size()) + 1 ; i++) {
            sub.push_back(i);
            backtrack(res, sub, i + 1, n,  k);
            sub.pop_back();
        }
    }
};
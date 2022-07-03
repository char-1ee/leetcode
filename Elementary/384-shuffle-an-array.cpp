class Solution {
public:
    Solution(vector<int>& nums) : v(nums) {
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int> data = v;
        int n = data.size();
        for (int i = n - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            swap(data[i], data[j]);
        }
        return data;
    }
    
private: 
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
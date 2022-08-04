class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        } 
        
        auto comp = [&m](int x, int y) {
            return m[x] > m[y];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        vector<int> res;
                
        for (auto t : m) {
            pq.push(t.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        for (int i = k - 1; i >= 0; i--) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
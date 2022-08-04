class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            if (pq.size() < k) {
                pq.push(num);
            } else { // size >= k
                if (pq.top() <= num) {
                    pq.pop();
                    pq.push(num);
                } 
            }
        }
        return pq.top();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
        
    }
};


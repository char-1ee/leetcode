class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
    
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int n : nums){
           add(n);
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > K) q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class KthLargest2 {
private:
    multiset<int> st;
    int K;

public:
    KthLargest(int k, vector<int> nums) {
        for (int num : nums) {
            st.insert(num);
            if (st.size() > k) st.erase(st.begin());
        }
        K = k;
    }
    
    int add(int val) {
        st.insert(val);
        if (st.size() > K) st.erase(st.begin());
        return *st.begin();
    }
};
#include <bits/stdc++.h>
using namespace std;

// Heap + dirty update with set
// Alternative: heap + double linked list (simulate stack)
class MaxStack {
private:
    priority_queue<pair<int, int>> pq;
    stack<pair<int, int>> s;
    unordered_set<int> st;
    int cnt = 0; 

    void cleanStack() {
        while (st.count(s.top().second)) {
            s.pop();
        }
    }

    void cleanHeap() {
        while (st.count(pq.top().second)) {
            pq.pop();
        }
    }

public:
    MaxStack() {
        
    }
    
    void push(int x) {
        auto p = make_pair(x, cnt);
        cnt++;
        s.push(p);
        pq.push(p);
    }
    
    int pop() {
        cleanStack();
        int res = s.top().first;
        st.insert(s.top().second);
        s.pop();
        return res;
    }
    
    int top() {
        cleanStack();
        return s.top().first;
    }
    
    int peekMax() {
        cleanHeap();
        return pq.top().first;
    }
    
    int popMax() {
        cleanHeap();
        int res = pq.top().first;
        int id = pq.top().second;
        pq.pop();
        st.insert(id);
        return res;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

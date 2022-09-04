#include <bits/stdc++.h>
using namespace std;

/** Two queues: push O(1), pop O(n) */
class MyStack {
private:
    queue<int> q1; // simulate the top of stack
    queue<int> q2; // simulate the rest of stack

public:
    MyStack() {}

    void push(int x) {
        if (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
    }

    int pop() {
        int i = top();
        q1.pop();
        return i;
    }

    int top() {
        if (q1.empty()) {
            for (int i = 0; i < q2.size() - 1; ++i) {
                q2.push(q2.front());
                q2.pop();
            }
            q1.push(q2.front());
            q2.pop();
        }
        return q1.front();
    }

    bool empty() { return q1.empty() && q2.empty(); }
};

/** One queue: push O(n), pop O(1) */
class MyStack2 {
public:
    MyStack2() {}

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }

private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
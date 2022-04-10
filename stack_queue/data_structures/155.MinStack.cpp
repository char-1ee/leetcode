/** Min stack by one stack */
class MinStack {
private: 
    int min_val;
    stack<int> s;

public:
    MinStack() {
        min_val = INT_MAX;
    }

    void push(int val) {
        if (val <= min_val) { 
            s.push(min_val); // first push
            min_val = val; // update
        }
        s.push(val); // second push
    }

    void pop() {
        int t = s.top(); s.pop(); // first pop
        if (t == min_val) { // which means the min value is already taken out
            min_val = s.top(); s.pop(); // second pop
        }
    }

    int top() {
        return s.top(); 
    }

    int getMin() {
        return min_val;
    }
}

/**
 * How the stack is not corrupted by min_val?
 * - By pushing/poping in pair (with conditional checks).
 *   Since min_val is always pushed/poped together with other values,
 *   it feels like the corrupted item is come or gone in pairs,
 *   thus no need to worry position problems.
 *
 * References:
 * - https://grandyang.com/leetcode/155/
 * - https://leetcode.com/problems/min-stack/discuss/49014/java-accepted-solution-using-one-stack
 * 
 */
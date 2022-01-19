/** Although same algorithms, but this code piece ran 5 times faster than mine. :-( */
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        _new.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shiftStack();
        int val = _old.top(); _old.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        shiftStack();
        return _old.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _old.empty() && _new.empty();
    }

    void shiftStack() {
        if (!_old.empty()) return;
        while (!_new.empty()) {
            _old.push(_new.top());
            _new.pop();
        }
    }

private:
    stack<int> _old, _new;
};

/**
 * ========================================================================================
 * A very exciting question: 
 * Do you know when we should use two stacks to implement a queue?
 * 
 * The application for this implementation is to separate read & write of a queue in multi-processing.
 * One of the stack is for read, and another is for write. 
 * They only interfere each other when the former one is full or latter is empty. 
 * 
 * When there's only one thread doing the read/write operation to the stack, there will always one stack empty. 
 * However, in a multi-thread application, if we have only one queue, for thread-safety, 
 * either read or write will lock the whole queue. In the two stack implementation, 
 * as long as the second stack is not empty, push operation will not lock the stack for pop.
 * 
 * =========================================================================================
 * Refer to:
 * 1. https://leetcode.com/problems/implement-queue-using-stacks/discuss/64284/Do-you-know-when-we-should-use-two-stacks-to-implement-a-queue
 * 2. https://stackoverflow.com/questions/2050120/why-use-two-stacks-to-make-a-queue/2050402#2050402
 */
package data_structures;

import java.util.*;

class MyQueue {

    private Stack<Integer> in, out;

    public MyQueue() {
        this.in = new Stack<>();
        this.out = new Stack<>();
    }

    public void push(int x) { // O(1)
        in.push(x);
    }

    // Amortized O(1), Worst-case O(n)
    public int pop() {
        shift();
        return out.pop();
    }

    public int peek() {
        shift();
        return out.peek();
    }

    public boolean empty() { // O(1)
        return in.empty() && out.empty();
    }

    private void shift() {
        if (!out.isEmpty())
            return;
        while (!in.empty()) {
            out.push(in.pop());
        }

    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
package data_structures;

import java.util.Stack;

/**
 * Min stack by two stacks.
 */
class MinStack {

    private Stack<Integer> s1; // contains normal values
    private Stack<Integer> s2; // contains minimum values

    /** initializes the stack object */
    public MinStack() {
        this.s1 = new Stack<>();
        this.s2 = new Stack<>();
    }

    /** pushes the element val onto the stack */
    public void push(int val) {
        s1.push(val);

        // CAUTION! Lazy evaluation to avoid `s2.peek()` throw EmptyStackException
        if (s2.isEmpty() || val <= s2.peek())
            s2.push(val);
        else
            s2.push(s2.peek());
    }

    /** removes the element on the top of the stack */
    public void pop() {
        s1.pop();
        s2.pop();
    }

    /** gets the top element of the stack */
    public int top() {
        return s1.peek();
    }

    /** retrieves the minimum element in the stack */
    public int getMin() {
        return s2.peek();
    }
}

/**
 * Min stack by self-defined linked list
 */
class MinStack2 {
    class Node {
        int val;
        int minVal;
        Node next; // next points to the bottom of a stack

        Node(int val, int minVal, Node next) {
            this.val = val;
            this.minVal = minVal;
            this.next = next;
        }
    }

    private Node head; // a movable node

    public MinStack2() {
        head = null;
    }

    public void push(int val) {
        if (head == null)
            head = new Node(val, val, null);
        else
            head = new Node(val, Math.min(val, head.minVal), head);
    }

    public void pop() {
        head = head.next; // remind the pointer direction
    }

    public int top() {
        return head.val;
    }

    public int getMin() {
        return head.minVal;
    }
}

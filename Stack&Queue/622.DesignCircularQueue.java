class MyCircularQueue {

    private int[] q;        // queue by array
    private int front, end; // two pointers
    private int size;       // numbers of in-queue elements
    private int length;     // length: size of array

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        this.q = new int[k];
        this.front = 0;
        this.end = -1;      // !IMPORTANT!
        this.size = 0;
        this.length = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if (isFull())   return false;
        end = (end + 1) % length;
        // alternatively: `if (++end == length) end = 0;`
        q[end] = value;
        size++;
        return true;
    }

     /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if (isEmpty())  return false;
        front = (front + 1) % length;
        size--;
        return true;
    }

    /** Get the front item form the queue. */
    public int Front() {
        return isEmpty() ? -1 : q[front];
    }

    /** Get the last item from the queue. */
    public int Rear() {
        return isEmpty() ? -1 : q[end];
    }

    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return size == length;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */

 /**
  * A good explanation: https://leetcode.com/problems/design-circular-queue/discuss/1141876/JS-Python-Java-C%2B%2B-or-Simple-Array-Solution-w-Explanation
  */
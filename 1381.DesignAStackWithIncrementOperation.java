import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

/** Deque but slow */
class CustomStack {

    private final Deque<Integer> dq;
    private int size;
    private final int limit;

    public CustomStack(int maxSize) {
        this.limit = maxSize;
        this.dq = new ArrayDeque<>();
        this.size = 0;
    }

    public void push(int x) {
        if (size < limit) {
            dq.addLast(x);
            size++;
        } else
            return;
    }

    public int pop() {
        if (size == 0)
            return -1;
        int res = dq.pollLast();
        size--;
        return res;
    }

    public void increment(int k, int val) {
        for (int i = 0; i < size; i++) {
            int t = dq.pollFirst();
            if (i < k)
                t += val;
            dq.addLast(t);
        }
    }
}

/**
 * Maintain a aux array with indicate increments.
 * https://leetcode.com/problems/design-a-stack-with-increment-operation/discuss/539716/JavaC%2B%2BPython-Lazy-increment-O(1)
 */
class CustomStackByIncrArray {

    private final Stack<Integer> s;
    private final int[] inc;
    private final int limit;
    private int size;

    public CustomStackByIncrArray(int maxSize) {
        this.s = new Stack<>();
        this.inc = new int[maxSize];
        this.limit = maxSize;
        this.size = 0;
    }

    public void push(int x) {
        if (size < limit) {
            s.push(x);
            size++;
        }
    }

    public int pop() {
        int i = size - 1;
        if (i < 0)
            return -1;
        if (i > 0)
            inc[i - 1] += inc[i];
        int res = s.pop() + inc[i];
        inc[i] = 0;
        size--;
        return res;

    }

    public void increment(int k, int val) {
        int cnt = Math.min(k, size) - 1;
        if (cnt >= 0)
            inc[cnt] += val;
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */

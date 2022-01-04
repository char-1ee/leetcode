package Array;

import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int thirdMax(int[] nums) {
        Queue<Integer> q = new PriorityQueue<>();
        for (int num : nums) {
            if (!q.contains(num))
                q.add(num);
            if (q.size() > 3)
                q.remove();
        }
        if (q.size() == 2)
            q.remove();
        return q.peek();
    }
}

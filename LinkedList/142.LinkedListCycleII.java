/**
 * Keypoints: 1. Linkedlist must close at tail if cycled; 2. In circular chasing
 * problems, faster always one circle further than slower when meet. 
 * References: https://www.cnblogs.com/hiddenfox/p/3408931.html
 */
class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next;
            slow = slow.next;
            if (slow == fast) {
                /** Dist of Head-to-meet == dist of Meet-to-CircleEntry */
                while (head != fast) {
                    fast = fast.next;
                    head = head.next;
                }
                return head;
            }
        }
        return null;
    }
}
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

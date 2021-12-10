class Solution {
    /** Fast-pointer and Slow-pointer */ 
    public boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    /** Recursion: but it BREAKS the original ll structure! */
    public boolean hasCycle2(ListNode head) {
        if (head == null || head.next == null) return false;
        if (head.next == head) return true;

        ListNode nextNode = head.next;
        head.next = head;
        boolean isCycle = hasCycle2(nextNode);  // Alternative for iteration : recursion
        return isCycle;
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

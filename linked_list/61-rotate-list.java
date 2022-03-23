/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    /** Recursive */
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null)
            return head;
        int cnt = 0;
        ListNode curr = head;
        while (curr != null) {
            curr = curr.next;
            cnt++;
        }
        return rotate(head, k % cnt);

    }

    private ListNode rotate(ListNode head, int k) {
        if (k == 0)
            return head;
        ListNode prev = head;
        ListNode tail = prev.next;
        while (tail.next != null) {
            prev = prev.next;
            tail = tail.next;
        }
        tail.next = head;
        prev.next = null;
        return rotate(tail, k - 1);
    }

    /** Count and cut */
    public ListNode rotateRight2(ListNode head, int k) {
        if (head == null || head.next == null)
            return head;
        ListNode curr = head;
        int n; // cnt of length
        for (n = 1; curr.next != null; n++) {
            curr = curr.next;
        }
        curr.next = head; // close into ring

        ListNode tail = head;
        // find new tail node (n - k%n - 1)th
        for (int i = 0; i < n - k % n - 1; i++) {
            tail = tail.next;
        }
        // find new head node (n - k%n)th
        ListNode newHead = tail.next;

        tail.next = null; // break the ring
        return newHead;
    }
}
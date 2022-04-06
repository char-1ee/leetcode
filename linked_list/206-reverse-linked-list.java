package linked_list;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    /** Iterative */
    public ListNode reverseLinkedList(ListNode head) {
        if (head == null)
            return null;
        ListNode prev = null; // should declare null here, rather than an empty node
        ListNode curr = head;

        while (curr != null) {
            ListNode nextTemp = curr.next; // Save next node
            /** FIGURE OUT */
            curr.next = prev; // Reverse (first time prev = null)
            prev = curr; // Used for next iteration
            curr = nextTemp; // Move to next node
        }
        return prev;
    }

    /** recursive 1 */
    public ListNode reverseList(ListNode head) {
        return reverseList(head, null);
    }

    private ListNode reverseList(ListNode curr, ListNode prev) {
        if (curr == null)
            return prev;
        ListNode next = curr.next;
        curr.next = prev;
        return reverseList(next, curr);
    }

    /** recursive 2 */
    public ListNode reverse(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode original_head = head.next;
        ListNode reversed_list = reverse(original_head);
        original_head.next = head;
        head.next = null;
        return reversed_list;
    }
}

/**
 * https://leetcode.com/problems/reverse-linked-list/discuss/440696/Easy-to-understand-recursive-solution-(-beats-98-takes-2-arguments-)
 * 
 */
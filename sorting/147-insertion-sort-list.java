package sorting;

class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode dummy = new ListNode(0, head);
        ListNode last = head, after = head.next;
        while (after != null) {
            if (last.val <= after.val) {
                last = last.next;
                after = after.next;
                continue;
            }
            ListNode prev = dummy;
            while (prev.next.val <= after.val) {
                prev = prev.next;
            }
            last.next = after.next;
            after.next = prev.next;
            prev.next = after;
            after = last.next;
        }
        return dummy.next;
    }
}

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
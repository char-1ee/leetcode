package LinkedList;

class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1) return head;
        
        ListNode dummy = new ListNode(-1, head);
        ListNode prev = dummy, curr = head;
        
        for (int i = 1; curr != null; i++) {
            if (i % k == 0) {
                prev = reverse(prev, curr.next);
                curr = prev.next;
            } else {
                curr = curr.next;
            }
        }
        return dummy.next;        
    }
    
    // since we cannot track a head of sublist but the previous node of sublist head
    private ListNode reverse(ListNode prev, ListNode tail) {
        ListNode last = prev.next; 
        ListNode curr = last.next;
        while (curr != tail) {
            last.next = curr.next;
            curr.next = prev.next;
            prev.next = curr;
            curr = last.next;       
        }
        return last; // new head
    }
}               
            
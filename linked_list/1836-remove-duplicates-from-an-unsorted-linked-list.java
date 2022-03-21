/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicatesUnsorted(ListNode head) {
        if (head == null || head.next == null)
            return head;
        HashMap<Integer, Integer> m = new HashMap<>();
        ListNode curr = head;
        ListNode dummy = new ListNode(-1, head);
        ListNode prev = dummy;
        
        while (curr != null) {
            m.put(curr.val, m.getOrDefault(curr.val, 0) + 1);
            curr = curr.next;
        }
        
        // while (head != null) {
        //     if (m.get(head.val) > 1) {
        //         prev.next = head.next;
        //         head.next = null;
        //         head = prev;
        //     }
        //     prev = head;
        //     head = head.next;
        // }
        
        while (prev.next != null) {
            if (m.get(prev.next.val) > 1) {
                prev.next = prev.next.next;
            } else {
                prev = prev.next;
            }
        }
        return dummy.next;
    }
}
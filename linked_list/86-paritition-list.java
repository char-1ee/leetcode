package linked_list;

import utils.ListNode;

class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode beforeList = new ListNode();
        ListNode afterList = new ListNode();
        ListNode p1 = beforeList, p2 = afterList;
        while (head != null) {
            if (head.val < x) {
                p1.next = head;
                p1 = p1.next;
            } else {
                p2.next = head;
                p2 = p2.next;
            }
            head = head.next;
        }
        p2.next = null;
        p1.next = afterList.next;
        return beforeList.next;
    }
}
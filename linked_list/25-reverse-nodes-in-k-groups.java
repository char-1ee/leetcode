package linked_list;

import utils.ListNode;

/**
 * Iterative
 */
class Solution {
    public ListNode reverseKGroupIteration(ListNode head, int k) {
        if (head == null || k == 1)
            return head;

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
        ListNode last = prev.next; // last node in sublist after reverse
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
// -1->1->2->3->4->5
//  |        |  |
// pre      cur next

// -1->3->2->1->4->5
//     |     |  |
//    cur   pre next


/**
 * Recursive:
 * 用 head 记录每段的开始位置，cur 记录结束位置的下一个节点，然后调用 reverse 函数来将这段翻转，
 * 然后得到一个 new_head，原来的 head 就变成了末尾，
 * 这时候后面接上递归调用下一段得到的新节点，返回 new_head 即可
 * 
 */
class Solution2 {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode curr = head;
        for (int i = 0; i < k; i++) {
            if (curr == null)
                return head;
            curr = curr.next;
        }
        ListNode newHead = reverse(head, curr);
        head.next = reverseKGroup(curr, k);
        return newHead;
    }

    /**
     * @param head the start node of a k-group
     * @param tail the next node of end node of a k-group
     * @return reversed list which head is now the end
     */
    private ListNode reverse(ListNode head, ListNode tail) {
        ListNode prev = tail;
        while (head != tail) { // using head without local copy
            ListNode tmp = head.next;
            head.next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
}
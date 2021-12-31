class Solution {

    /** Cut the length difference to simplified iteration */
    public ListNode getIntersectionNode1(ListNode headA, ListNode headB) {
        // boundary check
        if (headA == null || headB == null)  return null;   

        int lenA = getLength(headA), lenB = getLength(headB);
        if (lenB > lenA) {
            for (int i = 0; i < lenB - lenA; i++){
                headB = headB.next;
            }
        } else {
            for (int i = 0; i < lenA -lenB; i++) {
                headA = headA.next;
            }
        }
        /* Must check (headA != headB) for case of A totally equals to B */
        while (headB != null && headA != null && headA != headB) {  // Input: 1 [1] [1] 0 0
            headB = headB.next;
            headA = headA.next;
        }
        return (headA == headB) ? headB : null;
    }
    public int getLength(ListNode head) {
        int cnt = 0;
        while (head != null) {
            head = head.next;
            cnt++;
        }
        return cnt;
    }

    /** https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len! */
    public ListNode getIntersectionNode2(ListNode headA, ListNode headB) {
        // boundary check
        if (headA == null || headB == null) return null;

        ListNode a = headA;
        ListNode b = headB;

        // if a & b have different len, then we will stop the loop after second iteration
        while (a != b) {
            // for the end of first iteration, we just reset the pointer to the head of another linkedlist
            a = a == null ? headB : a.next;
            b = b == null ? headA : b.next;
        }
        return a;
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

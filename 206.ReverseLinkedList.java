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
    /** Iterative */
    public ListNode reverseLinkedList(ListNode head) {
        if (head == null) return null;
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode nextTemp = curr.next;  // Save next node
            /** FIGURE OUT */
            curr.next = prev;   // Reverse (first time prev = null) 
            prev = curr;    // Used for next iteration
            curr = nextTemp;    // Move to next node
        }
        return prev;
    } 

    /** Recursion */
    public ListNode reverseLinkedList2(ListNode head) {

    }

}
import java.util.Stack;

class ListNode {
    int val; 
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next;}
}

class Solution {
    void reorderList(ListNode head) {
        if (head == null || head.next == null) return;

        ListNode curr = head;
        Stack<ListNode> s = new Stack<>();

        while (curr != null) {
            s.push(curr);
            curr = curr.next;
        }
        curr = head;
        int mid = (s.size() - 1) / 2;
        while (mid-- > 0) {
            ListNode temp = curr.next;
            ListNode ins = s.pop();
            curr.next = ins;
            ins.next = temp;
            curr = temp;    // curr = curr.next
        }

        s.pop().next = null;    // cut off the list
    }
}
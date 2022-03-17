import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {

    /** Min heap */
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;

        ListNode root = new ListNode(-1);
        ListNode curr = root;
        PriorityQueue<ListNode> pq = new PriorityQueue<>(lists.length, new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                if (o1.val < o2.val)
                    return -1;
                else if (o1.val > o2.val)
                    return 1;
                else
                    return 0;
            }
        });

        for (ListNode l : lists) {
            if (l != null)
                pq.add(l);
        }

        while (pq.isEmpty() == false) {
            ListNode t = pq.poll();
            curr.next = t;
            curr = curr.next;
            if (curr.next != null)
                pq.add(curr.next);
        }
        return root.next;
    }

    class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
}
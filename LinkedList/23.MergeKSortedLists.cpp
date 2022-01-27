struct ListNode {
    int val; 
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:

    /** Merge k-1 times */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Extract every two front elements and then merge them, 
        // push back to the array. Recursively. 
        while (lists.size() > 1) {
            lists.push_back(merge(lists[0], lists[1]));
            lists.erase(lists.front());
            lists.erase(lists.front());
        }
        return lists.front();
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;
        return res->next;
    } 

    /** Min heap */
    public ListNode mergeKLists2(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;
        
        ListNode root = new ListNode(-1);
        ListNode curr = root;
        PriorityQueue<ListNode> pq = new PriorityQueue<>(lists.length, new Comparator<ListNode>(){
            @Override
            public int compare(ListNode o1, ListNode o2) {
                if (o1.val < o2.val) return -1;
                else if (o1.val > o2.val) return 1;
                else return 0;
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
}
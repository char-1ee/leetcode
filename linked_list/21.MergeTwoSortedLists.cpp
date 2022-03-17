struct ListNode {
    int val;
    ListNode * next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode * next): val(x), next(next) {};
};

class Solution {
public:
    /** iterative */
    ListNode* mergeTwoLists (ListNode* list1, ListNode* list2) {
        if (!list1)     return list2;
        else if (list1 && !list2)   return list1;

        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr = list1;
                list1 = list1->next;
            } else {
                curr = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1) curr = list1;
        if (list2) curr = list2;
        return res->next;
    }

    /** Recursive */
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1; // base cases

        if (l1->val <= l2->val) {
            l1->next = mergeLists(l1->next, l2);
            return l1;  // start with l1 head
        } else {
            l2->next = mergeLists(l2->next, l1);
            return l2;  // start with l2 head 
        }
    }
};
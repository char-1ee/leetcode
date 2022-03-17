struct ListNode {
    int val;
    ListNode * next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode * next): val(x), next(next) {};
};

class Solution {
public:

    /** Recursive */
    ListNode* swapNodes(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tmp = head->next;
        head->next = swapNodes(head->next->next);
        tmp->next = head;
        return tmp;
    }

    /** Iterative */
    ListNode* swapNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;
        while (curr->next && curr->next->next) {
            ListNode* ptr1 = curr->next;
            ListNode* ptr2 = curr->next->next;
            ptr1->next = ptr2->next;
            curr->next = ptr2;
            ptr2->next = ptr1;
            curr = curr->next->next;
        }
        return dummy->next;
    }
}
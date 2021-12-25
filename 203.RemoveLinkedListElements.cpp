struct ListNode {
     int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

    /** Iterative method */
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)  return NULL;

        while (head && head->val == val) {
            head = head->next;
        }
        ListNode* curr = head;
        while (curr->next) {
            if (curr->next->val == val)    curr->next = curr->next->next;
            else curr = curr->next;
        }       
        return head;
    }

    /** Recursive method */
    ListNode* removeElements2(ListNode* head, int val) {
        if (!head) return NULL;
        head->next = removeElements2(head->next, val);
        return head->val == val ? head->next : head;
    }
}
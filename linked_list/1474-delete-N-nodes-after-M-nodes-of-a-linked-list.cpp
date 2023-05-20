/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode *deleteNodes(ListNode *head, int m, int n) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *newHead = new ListNode(0);
        ListNode *curr = newHead;
        while (head) {
            for (int i = 0; i < m && head; i++) {
                curr->next = new ListNode(head->val);
                curr = curr->next;
                head = head->next;
            }
            for (int j = 0; j < n && head; j++) {
                head = head->next;
            }
        }
        return newHead->next;
    }
};

// Inplace solution
class Solution2 {
   public:
    ListNode *deleteNodes(ListNode *head, int m, int n) {
        if (!head || !head->next) return head;
        ListNode *curr = head;
        ListNode *last = head;
        while (curr) {
            for (int i = 0; i < m && curr; i++) {
                last = curr;
                curr = curr->next;
            }
            for (int j = 0; j < n && curr; j++) {
                curr = curr->next;
            }
            last->next = curr;
        }
        return head;
    }
};
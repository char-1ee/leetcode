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
    ListNode* deleteDuplicates1(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }

    ListNode* deleteDuplicates2(ListNode* head) {
        if (!head) return nullptr;
        ListNode* curr = head;
        while (curr) {
            int currVal = curr->val;
            ListNode* tmp = curr->next;
            while (tmp && tmp->val == currVal) {
                tmp = tmp->next;
            }
            curr->next = tmp;
            curr = curr->next;
        }
        return head;
    }
};
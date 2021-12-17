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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* mid = head;       // slow pointer
        ListNode* end = head->next; // fast pointer
        while (end && end->next) {
            mid = mid->next;
            end = end->next->next;
        }
        ListNode* sub2 = mid->next;     // sub2 points to right sublist
        mid->next = NULL;               // cut off two sublist by left sublist ending with NULL
        return merge(sortList(head), sortList(sub2));  
    }
    
    ListNode* merge(ListNode* sub1, ListNode* sub2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        
        while (sub1 && sub2) {
            if (sub1->val >= sub2->val) {
                curr->next = sub2;
                sub2 = sub2->next;
            } else {
                curr->next = sub1;
                sub1 = sub1->next;
            }
            curr = curr->next;
        }
        
        if (sub1)   curr->next = sub1;
        else if (sub2)  curr->next = sub2;
        return res->next;
    }
};
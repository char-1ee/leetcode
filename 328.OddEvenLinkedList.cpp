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

    /** Method 1: iteratively move odd node to before even node */
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
       
        while(even && even->next) {

            // throw the odd2 element after even1 to  after odd1 and before even1
            ListNode* tmp = odd->next;
            odd->next = even->next;
            even->next = even->next->next;
            odd->next->next = tmp;
            odd = odd->next;        // odd always points to the last odd element
            even = even->next;      // even always points to the last even element
        }
        
        return head;
    }

    /** Method 2: use a pointer to keep even nodes */
    ListNode* oddEvenList2(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = even;      // pointer to record start of even elements

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = temp;
        return head;
    }
};
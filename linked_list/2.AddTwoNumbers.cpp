#include '../utility.h'

class Solution {
public: 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        int num1, num2, carry;

        while (l1 || l2 || carry) {
            num1 = 0; 
            num2 = 0;
            if (l1) {
                num1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                num2 = l2->val;
                l2 = l2->next;
            }

            int temp = num1 + num2 + carry;
            carry = temp / 10;
            curr->next = new ListNode(temp % 10);
            curr = curr->next;
        }
        return res->next;
    }
};
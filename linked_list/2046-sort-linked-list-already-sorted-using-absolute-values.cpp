#include <bits/stdc++.h>

#include "../utils/utility.h"
using namespace std;

class Solution {
   public:
    ListNode *sortLinkedList(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *curr = head->next;
        ListNode *prev = head;
        while (curr) {
            ListNode *t = curr->next;
            if (curr->val >= 0) {
                prev = curr;
                curr = curr->next;
            } else {
                curr->next = head;
                head = curr;
                prev->next = t;
                curr = t;
            }
        }
        return head;
    }
};
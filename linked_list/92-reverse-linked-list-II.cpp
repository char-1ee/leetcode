#include <bits/stdc++.h>
#include "../utils/utility.h"
using namespace std;

class Solution {
public:
    // method 1
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next || left == right)
            return head;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;

        // prev = 1, curr = 2
        // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
        // 1 -> 3 -> 2 -> 4 -> 5 -> NULL
        // 1 -> 4 -> 3 -> 2 -> 5 -> NULL
        for (int i = left; i < right; i++) {
            ListNode* tmp = curr->next;
            curr->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        return dummy->next;
    }

    // method 2 (official solution)
    ListNode* reverseBetween2(ListNode* head, int m, int n) {
        if (!head || !head->next || m == n)
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (m > 1) {
            prev = curr;
            curr = curr->next;
            m--;
            n--;
        }
        ListNode* con = prev; // node just before the reversed list
        ListNode* tail = curr; // node of start of to-reverse list
        while (n > 0) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            n--;
        }
        if (con) {
            con->next = prev;
        } else {
            head = prev;
        }
        tail->next = curr;
        return head;
    }
};
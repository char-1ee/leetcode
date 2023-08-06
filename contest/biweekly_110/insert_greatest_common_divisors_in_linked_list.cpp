#include <bits/stdc++.h>
using namespace std;

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
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *curr = head;
        while (curr->next) {
            int val = gcd(curr->val, curr->next->val);
            ListNode *t = new ListNode(val);
            t->next = curr->next;
            curr->next = t;
            curr = t->next;
        }
        return head;
    }
};
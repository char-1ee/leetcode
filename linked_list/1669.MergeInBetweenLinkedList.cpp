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
#include <bits/stdc++.h>
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *ptra = list1;
        ListNode *ptrb = list1;
        for (int i = 0; i < b + 1; ++i)
        {
            if (i < a - 1)    ptra = ptra->next;
            if (i < b)  ptrb = ptrb->next;
        }
        ptra->next = list2;
        while (list2->next != NULL)
            list2 = list2->next;
        list2->next = ptrb->next;

        return list1;
    }
};
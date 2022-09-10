#include <bits/stdc++.h>
#include "../utils/utility.h"
using namespace std;

// Reverse list first then add-two-number-I
// Time O(n1 + n2), space O(max(n1, n2))
class Solution1 {
public:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev = nullptr;
        while (head) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int carry = 0, digit;
        ListNode* head = nullptr;
        
        while (l1 || l2 || carry) {
            int x1 = l1 ? l1->val : 0;
            int x2 = l2 ? l2->val : 0;
            digit = (carry + x1 + x2) % 10;
            carry = (carry + x1 + x2) / 10;
            
            ListNode* curr = new ListNode(digit);
            curr->next = head;
            head = curr;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return head;
    }
};

// Two stacks
// Time o(n1 + n2), space O(n1 + n2)
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;       
        while (l1 || l2) {
            if (l1) {
                s1.push(l1->val);
                l1 = l1->next;
            }
            if (l2) {
                s2.push(l2->val);
                l2 = l2->next;
            }
        } 

        int carry = 0, digit;
        ListNode* curr = nullptr;
        
        while (!s1.empty() || !s2.empty() || carry) {
            int x1 = 0, x2 = 0;
            if (!s1.empty()) {
                x1 = s1.top(); 
                s1.pop();
            }
            if (!s2.empty()) {
                x2 = s2.top();
                s2.pop();
            }
            digit = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            
            ListNode* node = new ListNode(digit);
            node->next = curr;
            curr = node;
        }       
        return curr;
    }
};

// 1. Add node without carry one
// 2. Plus carry and reverse
// time O(n1 + n2), space O(max(n1, n2));
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        
        while (curr1) {
            curr1 = curr1->next;
            len1++;
        }
        while (curr2) {
            curr2 = curr2->next;
            len2++;
        }
        
        curr1 = l1;
        curr2 = l2;
        ListNode* head = nullptr;
        
        while (len1 > 0 || len2 > 0) {
            int num = 0;;
            if (len1 >= len2) {
                num += curr1->val;
                curr1 = curr1->next;
                len1--;
            }
            if (len1 < len2) {
                num += curr2->val;
                curr2 = curr2->next;
                len2--;
            }
            ListNode* node = new ListNode(num);
            node->next = head;
            head = node;
        }
        
        ListNode* curr = head;
        head = nullptr;
        int carry = 0;
        
        while (curr ||carry) {
            int x = 0;
            if (curr) {
                x = curr->val;
                curr = curr->next;
            }
            int digit = (x + carry) % 10;
            carry = (x + carry) / 10;
            
            ListNode* node = new ListNode(digit);
            node->next = head;
            head = node;
        }
        return head;
    }
};
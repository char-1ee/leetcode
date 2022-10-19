#include "../utils/utility.h"
using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        int res = 0;
        while (curr) {
            res = res * 2 + curr->val;
            // alternative
            // res = (res << 1) | curr->val;
            curr = curr->next;
        }
        return res;
    }
};
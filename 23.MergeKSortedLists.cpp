struct ListNode {
    int val; 
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Extract every two front elements and then merge them, 
        // push back to the array. Recursively. 
        while (lists.size() > 1) {
            lists.push_back(merge(lists[0], lists[1]));
            lists.erase(lists.front());
            lists.erase(lists.front());
        }
        return lists.front();
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;
        return res->next;
    } 
}
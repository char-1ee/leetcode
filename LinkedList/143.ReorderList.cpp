struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /** In-place merge */
    void reorderList(ListNode *head)
    {
        if (head || head->next || head->next->next)
            return;

        // halve list
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;

        // reverse the sublist [mid..n]
        ListNode *prev = NULL;
        ListNode *curr = mid;
        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // merge two sublists
        while (prev && head)
        {
            ListNode *temp = head->next;
            head->next = prev;
            prev = prev->next;
            head->next->next = temp;
            head = temp;
        }
    }
};
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        // duplicate nodes
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            Node* copy = new Node(curr->val);
            copy->next = nextNode;
            curr->next = copy;
            curr = nextNode;
        }

        // copy random ptrs
        curr = head;
        while (curr) {
            Node* copy = curr->next;
            if (curr->random) copy->random = curr->random->next;
            curr = curr->next->next;
        }

        // depart
        Node* dummy = new Node(-1);
        Node* newHead = dummy;
        curr = head;
        while (curr) {
            Node* tmp = curr->next->next;

            Node* copy = curr->next;
            newHead->next = copy;
            newHead = copy;

            curr->next = tmp;
            curr = curr->next;
        }

        return dummy->next;
    }
};
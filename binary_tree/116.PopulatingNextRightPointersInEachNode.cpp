/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    /** Recursive */
    Node* connect(Node* root) {
        if (!root) return NULL;
        if (root->left) root->left->next = root->right;
        if (root->right) root->right->next = (root->next == NULL) ? NULL : root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }

    /** Iterative */
    Node* connectIterative(Node* root) {
        if (!root) return NULL;
        
        queue<Node*> q{{root}};
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                Node* t = q.front(); q.pop();
                if (i > 1) t->next = q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return root;
    }
};
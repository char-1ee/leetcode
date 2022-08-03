class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

// Solution 1 without comparing vals.
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return nullptr;

        if (node->right) {
            Node* t = node->right;
            while (t->left) {
                t = t->left;
            }
            return t;
        } else if (node->parent) {
            Node* p = node->parent;
            while (p && p->right == node) {
                node = p;
                p = p->parent;
            }
            return p;
        }
        return nullptr;
    }
};

// Solution 2 without comparing vals.
class Solution2 {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return nullptr;

        if (node->right) {
            Node* t = node->right;
            while (t->left) t = t->left;
            return t;
        }
        while (node) {
            if (!node->parent) return nullptr;
            if (node == node->parent->left) return node->parent;
            node = node->parent;
        }
        return node;
    }
};

// Solution 3 comparing vals.
class Solution3 {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return nullptr;
        Node* res = nullptr;
        if (node->right) {
            res = node->right;
            while (res->left) res = res->left;
        } else {
            res = node->parent;
            while (res && res->val < node->val) res = res->parent;
        }
        return res;
    }
};

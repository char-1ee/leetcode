#include <bits/stdc++.h>
#include "../utils/utility.h"

using namespace std;

// DFS Recursion: inorder traversal to fetch sorted nodes.
// time O(N), space O(N). All nodes are iterated.
class Solution1 {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        inorder(root, vals);
        return vals[k - 1];
    }

    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};


// DFS Iteration: stop when counted k-th.
// time O(H + k), space O(H). H is tree height.
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> s;
        while (true) {
            while (root) {
                s.push_back(root);
                root = root->left;
            }

            root = s.back();
            s.pop_back();

            if (--k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return root->val;
    }
};

// Divide and Conquer:
// If k < (cnt of left subtree nodes) k-th node is in left subtree.
// If k > (cnt of right subtree nodes) k-th node is in right subtree.
// Otherwise k-th is the root node.
class Solution3 {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left); // get left subtree count

        if (k < cnt + 1) {
            return kthSmallest(root->left, k);
        } else if (k > cnt + 1) {
            return kthSmallest(root->right, k - cnt - 1);
        }
        return root->val; // k == cnt + 1
    }

    int count(TreeNode* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};

// Follow-up: What if the BST is modified (insert/delete operations) often
// and you need to find the kth smallest frequently? (Bytes stream -> design data structure)
// Solution: keep left subtree count as new attributes in a node.
class Solution4 {
public:
    struct mTreeNode {
        int val;
        int count; // count of left subtree nodes
        mTreeNode* left;
        mTreeNode* right;
        mTreeNode(int x)
            : val(x)
            , count(1)
            , left(nullptr)
            , right(nullptr) {}
    };

    // Re-build tree with new struct
    mTreeNode* build(TreeNode* root) {
        if (!root) return nullptr;

        mTreeNode* t = new mTreeNode(root->val);
        t->left = build(root->left);
        t->right = build(root->right);

        if (t->left) t->count += t->left->count;
        if (t->right) t->count += t->right->count;

        return t;
    }

    int kthSmallest(TreeNode* root, int k) {
        mTreeNode* node = build(root);
        return kthSmallestCore(node, k);
    }

    int kthSmallestCore(mTreeNode* root, int k) {
        // left subtree may not exist
        if (root->left) {
            int cnt = root->left->count;
            if (k < cnt + 1) {
                return kthSmallestCore(root->left, k);
            } else if (k > cnt + 1) {
                return kthSmallestCore(root->right, k - cnt - 1);
            } else {
                return root->val;
            }
        } else { // when subtree not exists
            if (k == 1) return root->val;
            return kthSmallestCore(root->right, --k);
        }
    }
};
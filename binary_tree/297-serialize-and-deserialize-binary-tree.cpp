#include "../utils/utility.h"
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeCore(root, out);
        return out.str();
    }
    
    void serializeCore(TreeNode* root, ostringstream& out) {
        if (root == nullptr) {
            out << " null";
            return;
        }
        out << " " << to_string(root->val);
        serializeCore(root->left, out);
        serializeCore(root->right, out);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeCore(in);
    }
    
    TreeNode* deserializeCore(istringstream& in) {
        string s_val;
        in >> s_val;
        if (s_val == "null") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(s_val));
        root->left = deserializeCore(in);
        root->right = deserializeCore(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
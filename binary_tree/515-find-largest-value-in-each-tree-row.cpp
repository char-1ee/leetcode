#include "../utils/utility.h"
using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q{{root}};

        while (!q.empty()) {
            int size = q.size();
            int levelMax = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                levelMax = max(levelMax, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(levelMax);
        }
        return res;
    }
};
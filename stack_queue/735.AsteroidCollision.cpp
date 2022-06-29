class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        vector<int> res;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > 0)
                res.push_back(A[i]);
            else if (res.empty() || res.back() < 0)
                res.push_back(A[i]);
            else if (res.back() <= -A[i]) {
                if (res.back() < -A[i]) i--;
                res.pop_back();
            }
        }
        return res;
    }
};
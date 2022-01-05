class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> e = h;
        sort(e.begin(), e.end());
        int cnt = 0;
        for (int i = 0; i < h.size(); ++i) 
            cnt += h[i] != e[i];
        return cnt;
    }
};
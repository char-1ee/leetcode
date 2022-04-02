class Solution {
public:
    // cnblogs.com/grandyang/p/14285754.html
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        vector<int> cnt(26, INT_MAX);
        for (string word : A) {
            vector<int> t(26);
            for (char c : word) ++t[c - 'a'];
            for (int i = 0; i < 26; ++i) {
                cnt[i] = min(cnt[i], t[i]);
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};

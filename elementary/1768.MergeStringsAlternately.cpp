class Solution {
public:
    string mergesAlternately(string word1, string word2) {
        string res = "";
        int l1 = word1.length();
        int l2 = word2.length();

        for (int i = 0; i < l1 || i < l2; ++i) {
            if (i < l1)     res.push_back(word1[i]);
            if (i < l2)     res.push_back(word2[i]);
        }
        return res;
    }
};
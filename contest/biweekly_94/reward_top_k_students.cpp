#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

class Solution {
   public:
    vector<int> topStudents(vector<string> &pos, vector<string> &neg,
                            vector<string> &report, vector<int> &id, int k) {
        unordered_set<string> st1(pos.begin(), pos.end());
        unordered_set<string> st2(neg.begin(), neg.end());
        vector<pair<int, int>> t;

        for (int i = 0; i < id.size(); i++) {
            int rank = 0;
            string word;
            istringstream ss(report[i]);
            while (ss >> word) {
                if (st1.count(word))
                    rank += 3;
                else if (st2.count(word))
                    rank -= 1;
            }
            t.emplace_back(make_pair(rank, id[i]));
        }

        sort(t.begin(), t.end(), comp);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(t[i].second);
        }
        return res;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        string res = time;
        set<int> s{time[0], time[1], time[3], time[4]};
        string str(s.begin(), s.end());
        for (int i = res.size() - 1; i >= 0; --i) {
            if (res[i] == ':') continue;
            int pos = str.find(res[i]);
            if (pos == str.size() - 1) {
                res[i] = str[0];
            } else {
                char next = str[pos + 1];
                if (i == 4) {
                    res[i] = next;
                    return res;
                } else if (i == 3 && next <= '5') {
                    res[i] = next;
                    return res; 
                } else if (i == 1 && (res[0] != '2' || (res[0] == '2' && next <= '3'))) {
                    res[i] = next;
                    return res;
                } else if (i == 0 && next <= '2') {
                    res[i] = next;
                    return res;
                }
                res[i] = str[0];
            }
        }
        return res;
    }
};
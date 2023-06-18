#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.length();
        int m = shift.size();
        for (auto v : shift) {
            cout << "===== Test for " << v[0] << " " << v[1] << "=====" << endl;
            int len = v[1] % n;
            cout << "length: " << len << endl;
            if (v[0]) { // right
                string t = s.substr(n - len);
                cout << "t: " << t << endl;
                s = t + s.substr(0, n - len);
                cout << "s: " << s << endl;
            } else { // left
                string t = s.substr(0, len);
                cout << "t: " << t << endl;
                s = s.substr(len, n - len) + t;
                cout << "s: " << s << endl;

            }
        }
        return s;
    }
}; 
#include <bits/stdc++.h>

#include <cstddef>
#include <cstdio>
#include <regex>
#define ll long long
using namespace std;

bool check(vector<char> &v) {
    int n = v.size();
    if (n < 3) return false;
    if (v.back() == 'M' && v[n - 2] == 'C' && v[n - 3] == 'A') {
        return true;
    }
    return false;
}

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n < 4) {
        if (s == "ACM")
            cout << 0 << endl;
        else
            cout << s.length() << endl;
    } else {
        vector<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] != 'M' || st.size() < 2) {
                st.push_back(s[i]);
                continue;
            }

            // when meet 'M'
            if (st.size() < 3) {
                st.push_back(s[i]);
                if (check(st)) {
                    st.pop_back();
                    st.pop_back();
                    st.pop_back();
                }
            } else {  // xxxM
                st.push_back(s[i]);
                while (check(st)) {
                    st.pop_back();
                    st.pop_back();
                    st.pop_back();
                }
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}
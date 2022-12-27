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

void solution(string &s) {
    int n = s.size();
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
}

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1 = "ACCMACACMM";  // 4
    string s2 = "CMMAMAMAMA";
    string s3 = "A";
    string s4 = "AC";
    string s5 = "ACM";                  // 0
    string s6 = "CAM";                  // 3
    string s7 = "ACCMACACMMAACMACMCM";  // 4
    string s8 = "ACAM";

    solution(s1);
    solution(s2);
    solution(s3);
    solution(s4);
    solution(s5);
    solution(s6);
    solution(s7);
    solution(s8);

    return 0;
}
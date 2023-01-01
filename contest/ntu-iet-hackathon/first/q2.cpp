#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string b = "NTU IET CUP 2022!";
    string s;
    getline(cin, s);

    for (int i = 0; i < b.length(); i++) {
        if (s[i] == '#') {
            cout << b[i] << endl;
        }
    }

    return 0;
}
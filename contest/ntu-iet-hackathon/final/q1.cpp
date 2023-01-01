#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Note: cannot pass test cases

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> n >> m;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;
        if (op == "AND") {
            ll l, r, v;
            cin >> l >> r >> v;
            // and
            for (int i = l; i <= r; i++) {
                A[i] &= v;
            }
        } else if (op == "UPD") {
            ll x, v;
            cin >> x >> v;
            A[x] = v;
        } else if (op == "QUE") {
            ll l, r, mx = 0;
            cin >> l >> r;
            // return max
            for (int i = l; i <= r; i++) {
                mx = max(mx, A[i]);
            }
            cout << mx << endl;
        }
    }
    return 0;
}
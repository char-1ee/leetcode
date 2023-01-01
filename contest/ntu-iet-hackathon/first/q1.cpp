#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    if (n == 1) {
        cout << A[0] << endl;
        return 0;
    }

    ll res = 0;
    sort(A.begin(), A.end());
    for (int i = 1; i < n; i++) {
        res += A[i];
    }
    cout << res << endl;

    return 0;
}
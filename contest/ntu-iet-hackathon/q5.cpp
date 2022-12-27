#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int res = 1;
    vector<int> dec(n, 1), inc(n, 1);
    for (int i = 1; i < n; ++i) {
        if (A[i - 1] > A[i]) {
            dec[i] = inc[i - 1] + 1;
        } else if (A[i - 1] < A[i]) {
            inc[i] = dec[i - 1] + 1;
        }
        res = max(res, max(dec[i], inc[i]));
    }
    cout << res << endl;
    return 0;
}
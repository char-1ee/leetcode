#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cntA = 0, cntB = 0;;
    cin >> n >> m;
    vector<int> A(n + 1), B(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        A[a]++;
        B[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] < n) cntA++;
        if (B[i] < n) cntB++;
    }
    cout << min(cntA, cntB) << endl;
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll sum = 0;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    sort(B.begin(), B.end(), greater<>());
    for (int i = 0; i < n; i++) {
        sum += i * B[i] + A[i];
    }
    cout << sum << endl;
    
    return 0;
}
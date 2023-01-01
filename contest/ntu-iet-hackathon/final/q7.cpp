#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    if (sum >= k) {
        sum -= (k + 1) / 2;
    } else {
        sum = 0;
    }
    cout << sum << endl;
    
    return 0;
}
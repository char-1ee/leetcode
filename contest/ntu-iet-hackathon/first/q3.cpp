#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> cards;

void swp() {
    int x;
    cin >> x;
    swap(cards[x], cards[x + 1]);
}

void cnt() {
    int l, r, x, cnt = 0;
    cin >> l >> r >> x;

    // brute force
    for (int i = l; i <= r; i++) {
        if (cards[i] == x) cnt++;
    }

    // TODO:
    // ideally, shld use some look-up tables that records information including:
    // number x, index [l, r] or the bound where x appears, count of x in some
    // range/bounds.

    cout << cnt << endl;
}

void add() {
    int x;
    cin >> x;
    cards.push_back(x);
}

void solution(string &op) {
    if (op == "swp")
        swp();
    else if (op == "cnt")
        cnt();
    else if (op == "add")
        add();
}

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;
        solution(op);
    }
    return 0;
}
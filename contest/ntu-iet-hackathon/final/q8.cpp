#include <bits/stdc++.h>
#define ll long long
#define double long double
using namespace std;

vector<double> plane(double x1, double y1, double z1, double x2, double y2,
                              double z2, double x3, double y3, double z3) {
    vector<double> res;
    double a1 = x2 - x1;
    double b1 = y2 - y1;
    double c1 = z2 - z1;
    double a2 = x3 - x1;
    double b2 = y3 - y1;
    double c2 = z3 - z1;
    res[0] = b1 * c2 - b2 * c1;
    res[1] = a2 * c1 - a1 * c2;
    res[2] = a1 * b2 - b1 * a2;
    res[3] = (-res[0] * x1 - res[1] * y1 - res[2] * z1);
    return res;
}

double distance(double a1, double b1, double c1, double a2, double b2, double c2) {
    double d = (a1 * a2 + b1 * b2 + c1 * c2);
    double e1 = sqrt(a1 * a1 + b1 * b1 + c1 * c1);
    double e2 = sqrt(a2 * a2 + b2 * b2 + c2 * c2);
    d = d / (e1 * e2);
    // double pi = 3.14159;
    // double A = (180 / pi) * (acos(d));
    return acos(d);
}

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
        cin >> a1 >> a2 >> a3;
        cin >> b1 >> b2 >> b3;
        cin >> c1 >> c2 >> c3;
        cin >> d1 >> d2 >> d3;
        vector<double> p1 = plane(a1, b1, c1, a2, b2, c2, a3, b3, c3);
        vector<double> p2 = plane(b1, c1, d1, b2, c2, d2, b3, c3, d3);
        double res = distance(p1[0], p1[1], p1[2], p2[0], p2[1], p2[2]);
        cout << res << endl;
    }

    return 0;
}
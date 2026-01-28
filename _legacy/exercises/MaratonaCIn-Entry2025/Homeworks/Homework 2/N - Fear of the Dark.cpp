#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct Point {
    double x, y;
};

double d(Point p, Point q) {
    return sqrt(pow(q.x - p.x, 2) + pow(q.y - p.y, 2));
}

int solve() {
    double x, y;

    Point O = {0, 0};

    cin >> x >> y;
    Point P = {x, y};

    cin >> x >> y;
    Point A = {x, y};

    cin >> x >> y;
    Point B = {x, y};

    auto answ1 = max(d(O, A), d(P, A));
    auto answ2 = max(d(O, B), d(P, B));
    auto answ3 = max(d(O, A), max(d(P, B), d(A, B) / 2));
    auto answ4 = max(d(O, B), max(d(P, A), d(A, B) / 2));

    cout << min(min(answ1, answ2), min(answ3, answ4)) << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(10) << fixed;

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
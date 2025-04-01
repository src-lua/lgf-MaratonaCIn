#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double x, y;
    cin >> x >> y;

    y--;

    if (y < .5) {
        if (x == 0) {
            cout << "ALL GOOD" << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    else {
        cout << fixed;
        cout.precision(9);
        cout << -(x / y) << endl;
    }

    return 0;
}
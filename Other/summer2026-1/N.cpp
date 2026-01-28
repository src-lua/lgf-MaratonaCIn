/**
 * Author:      Lua
 * Problem:     N
 * Link:        https://vjudge.net/contest/781528#problem/N
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    while (!(a == 0 && b == 0 && c == 0)) {
        if (c - b == b - a) {
            cout << "AP " << c + c - b << endl;
        } else {
            cout << "GP " << (c * c) / b << endl;
        }

        cin >> a >> b >> c;
    }

    return 0;
}
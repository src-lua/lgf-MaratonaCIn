#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int x, y; cin >> x >> y;

    cout << 2 << endl;
    cout << x-1 << ' ' << x << endl;
    cout << x   << ' ' << y << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int a, b;
    cin >> a >> b;

    if (a >= b) cout << a << endl;
    else {
        if (a - (b-a) > 0) cout << a - (b-a) << endl;
        else cout << 0 << endl;
    }

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
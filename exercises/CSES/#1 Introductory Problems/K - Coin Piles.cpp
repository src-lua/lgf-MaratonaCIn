#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int a, b;
    cin >> a >> b;

    if ((2*a-b) % 3 == 0 && 2*a >= b && (2*b-a) % 3 == 0 && 2*b >= a) cout << "YES\n";
    else cout << "NO\n";

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
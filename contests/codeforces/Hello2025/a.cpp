#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, m; cin >> n >> m;

    cout << max(n,m) + 1 << endl;

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
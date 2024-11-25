#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;

    int mx = INT_MIN;
    int mn = INT_MAX;

    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;

        mx = max(mx, x);
        mn = min(mn, x);
    }
    
    cout << (mx - mn) * (n - 1) << '\n';

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
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n;
    cin >> n;

    int x;
    int maxvalue = INT_MIN;

    for (int i = 0; i < n; i++) {
        cin >> x;
        maxvalue = max(maxvalue, x);
    }

    cout << maxvalue << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc;
    cin >> tc;
    while (tc--) {
        cout << "Case " << ++c << ": ";
        solve();
    }

    return 0;
}
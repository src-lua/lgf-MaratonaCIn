#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> arr(n + 1), pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] ^ arr[i];
    }
    string s; cin >> s;

    int x[2] = {0, 0};
    for (int i = 0; i < n; i++) x[s[i] - '0'] ^= arr[i + 1];

    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        
        if (op == 1) {
            int l, r; cin >> l >> r;

            int v = pref[r] ^ pref[l - 1];

            x[0] ^= v;
            x[1] ^= v;
        }

        if (op == 2) {
            int g; cin >> g;
            cout << x[g] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) solve();

    return 0;
}
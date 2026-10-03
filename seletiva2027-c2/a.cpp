#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;

    vector<array<int,26>> pref_a(n + 1), pref_b(n + 1);
    for (int i = 0; i < n; i++) {
        pref_a[i + 1] = pref_a[i];
        pref_b[i + 1] = pref_b[i];

        pref_a[i + 1][a[i] - 'a']++;
        pref_b[i + 1][b[i] - 'a']++;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int ans = 0;
        for (int c = 0; c < 26; c++) {
            int ca = pref_a[r][c] - pref_a[l - 1][c];
            int cb = pref_b[r][c] - pref_b[l - 1][c];
            ans += abs(ca - cb);
        }
        cout << ans/2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) solve();

    return 0;
}
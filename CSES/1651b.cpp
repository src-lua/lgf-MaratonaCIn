/**
 * Author:      Lua
 * Problem:     1651 - Range Update Queries
 * Link:        https://cses.fi/problemset/task/1651
 * Status:      AC
 * Created:     11-07-2026 23:18:27
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<ll> arr(n); for (auto &x : arr) cin >> x;

    const int batch_size = sqrt(n);
    vector<tuple<int, int, ll>> batchs; batchs.reserve(batch_size);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 1) {
            int l, r, x; cin >> l >> r >> x; l--, r--;
            batchs.emplace_back(l, r, x);
        }

        else if (op == 2) {
            int idx; cin >> idx; idx--;

            ll ans = arr[idx];
            for (auto &[l, r, x] : batchs) if (l <= idx && idx <= r) ans += x;

            cout << ans << '\n';
        }

        if (batchs.size() >= batch_size) {
            vector<ll> updt(n+1, 0);
            for (auto &[l, r, x] : batchs) updt[l] += x, updt[r+1] -= x;
            
            for (int i = 0; i < n; i++) arr[i] += updt[i], updt[i+1] += updt[i];
            
            batchs.clear();
        }
    }

    return 0;
}

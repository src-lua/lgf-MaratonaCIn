/**
 * Author:      Lua
 * Problem:     G
 * Link:        https://vjudge.net/contest/781528#problem/G
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

ll solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (auto& [d, f] : arr) cin >> d >> f;
    sort(arr.rbegin(), arr.rend());

    priority_queue<ll> pq;

    ll l, p;
    cin >> l >> p;
    ll curr = l - p;
    ll idx = 0;

    ll ans = 0;
    while (curr > 0) {
        while (idx < n && arr[idx].first >= curr) pq.push(arr[idx++].second);
        if (pq.empty()) {
            cout << -1 << endl;
            return 0;
        }
        curr -= pq.top();
        pq.pop();
        ans++;
    }

    cout << ans << endl;
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) solve();

    return 0;
}
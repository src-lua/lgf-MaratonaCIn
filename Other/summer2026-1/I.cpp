/**
 * Author:      Lua
 * Problem:     I
 * Link:        https://vjudge.net/contest/781528#problem/I
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    ll ans = 0;

    ll curr = arr[0];
    for (auto e : arr) {
        if (e < curr) ans += curr-e;
        curr = max(e, curr);
    }

    cout << ans << endl;

    return 0;
}
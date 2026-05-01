/**
 * Author:      Lua
 * Problem:     I - Ice-cream Knapsack
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101991/problem/I
 * Status:      AC
 * Created:     04-04-2026 14:08:17
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

void solve() {
    ll n, k; cin >> n >> k;

    vector<pii> arr(n);
    for (auto& [p, v] : arr) cin >> p;
    for (auto& [p, v] : arr) cin >> v;

    sort(arr.begin(), arr.end());

    ll maxPrice = arr[k-1].first;
    arr.resize(upper_bound(arr.begin(), arr.end(), pii{maxPrice, LLONG_MAX}) - arr.begin());

    nth_element(arr.begin(), arr.begin() + k, arr.end(), [](pii a, pii b){
        return a.second > b.second;
    });

    ll ans = 0;
    for (int i = 0; i < k; i++) ans += arr[i].second;

    cout << maxPrice << ' ' << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("icecream.in", "r", stdin);

    int tc; cin >> tc; while (tc--) {
        solve();
        if (tc) cout << '\n';
    }
}
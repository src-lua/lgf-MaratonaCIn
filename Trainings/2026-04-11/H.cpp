/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/H
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define ll long long
using namespace std;

ll n, k;

vector<ll> getDiv(ll n) {
    vector<ll> div;
    for (ll i = 1; i * i <= n && i <= k; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n/i && n/i <= k) div.push_back(n/i);
        }
    }
    return div;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k;
    vector<ll> aux(n);
    ll ans = 0;
    

    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        aux[i] = x;
    }

    for (int mask = 1; mask < (1 << (n)); mask++) {
        ll l = 1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                l = lcm(l, aux[i]);
                if (l > 1e12) break;
            }
        }
        ans += (__builtin_popcount(mask) % 2 ? 1 : -1) * k/l;
    }

    cout << ans << endl;

    return 0;
}

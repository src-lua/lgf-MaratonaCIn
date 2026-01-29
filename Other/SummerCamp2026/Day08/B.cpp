/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://vjudge.net/contest/784977#problem/B
 * Status:      AC
 * Created:     28-01-2026 16:28:16
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

void solve() {
    ll c, r , s;
    cin >> c >> r >> s;

    ll total = c + r;
    ll spons = (total+s-1)/s;
    
    ll mn = spons - min(spons, r);

    ll rfill = (r+s -1) / s;

    ll mx = spons - rfill;

    cout << mx << ' ' << mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
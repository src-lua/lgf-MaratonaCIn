/**
 * Author:      Lua
 * Problem:     C
 * Link:        https://vjudge.net/contest/796519#problem/C
 * Status:      AC
 * Created:     14-03-2026 09:15:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

// count(k) em [l, r] * k
// count(k) = (f-l)/k+1 => 
// count(k) * k == ((f-l)/k+1)k == (f-l) + k
inline ll get(ll l, ll r, ll k) {
    ll first = l + ((k - (l%k)) % k);
    ll last = r - (r%k);
    return (first > last ? 0 : (last-first) + k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll l, r; cin >> l >> r;

    ll ans = 0;
    for (ll d = 1; d <= (ll)sqrt(r); d++) ans += get(l, r, d);

    // X = d * j
    for (ll j = 1; j <= (ll)sqrt(r); j++) {
                                           // ceil(l/j)
        ll dlo = max((ll)sqrt(r) + 1, (l + (j-1)) / j);
        ll dhi = r / j;
        if (dlo <= dhi) ans += (dhi - dlo + 1) * (dlo + dhi) / 2;
    }

    cout << ans << '\n';

    return 0;
}

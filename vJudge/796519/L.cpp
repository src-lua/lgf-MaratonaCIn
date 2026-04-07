/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://vjudge.net/contest/796519#problem/L
 * Status:      AC
 * Created:     14-03-2026 09:15:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ld = double;
using ll = long long;

ld a, b, c;

ld f(ll x) {
    return a*b/x + c*x;
}

ll ternary_search(ll lo, ll hi) { // minimiza f em [lo, hi]
    while (hi - lo > 2) {
        ll m1 = lo + (hi - lo) / 3;
        ll m2 = hi - (hi - lo) / 3;
        if (f(m1) < f(m2)) hi = m2;
        else lo = m1;
    }
    ll ans = lo;
    for (ll x = lo; x <= hi; x++)
        if (f(x) < f(ans)) ans = x;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(3) << fixed;

    cin >> a >> b >> c;
    cout << f(ternary_search(1, 1e12)) << '\n';

    return 0;
}

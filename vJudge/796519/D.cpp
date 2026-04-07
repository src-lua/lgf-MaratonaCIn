/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://vjudge.net/contest/796519#problem/D
 * Status:      AC
 * Created:     14-03-2026 09:15:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// n-1 + n-2 ... n-k == (k)n - k(k+1)/2
inline ll f(ll n, ll k) {
    return k*n - (k*(k+1))/2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    ll ops = ((n-1)*n)/2;

    ll l = 0, r = n-1;
    while (l <= r) {
        ll m = l + (r-l)/2;

        if (f(n, m) >= (ops+1)/2) r = m-1;
        else l = m + 1;
    }

    cout << l << '\n';

    return 0;
}

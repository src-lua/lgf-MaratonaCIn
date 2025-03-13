#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll fexpll(ll a, ll b, ll mod) {
    ll answ = 1;
    while (b > 0) {
        if (b % 2 == 1) answ = (answ * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return answ;
}

int solve() {

    int a, b, c; cin >> a >> b >> c;

    cout << fexpll(a, fexpll(b,c, MOD-1), MOD) << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
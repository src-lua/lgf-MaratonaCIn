#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {
    ll n, k; cin >> n >> k;

    ll sum = ((k + (n+k-1)) * n) / 2;

    ll mn = LLONG_MAX;

    for (int i = 1; i <= n; i++) {
        ll term = ((k + (k+i-1)) * i) / 2;

        mn = min(mn, abs((sum-term)-term));

    }

    cout << mn << endl;
    



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
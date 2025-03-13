#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int n, q; cin >> n >> q;
    vector<int> arr(n);
    vector<ll> prefix(n+1);
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i+1] = prefix[i] + arr[i];
    }

    ll l, r, k;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> k;
    
        ll lq = prefix[l-1];
        ll rq = prefix[n] - prefix[r];

        if ((lq + rq + (r-l+1) * k) % 2 == 1) cout << "YES\n";
        else cout << "NO\n";
    }

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
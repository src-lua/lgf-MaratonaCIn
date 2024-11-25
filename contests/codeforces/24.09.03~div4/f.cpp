#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    ll n, q; cin >> n >> q;

    vector<ll> arr(n);
    vector<ll> prefix(n+1);
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i+1] = prefix[i] + arr[i];
    }

    ll sum = prefix[n];

    ll a, b;

    for (int i = 0; i < n; i++) {
        arr.push_back(arr[i]);
        prefix.push_back(prefix.back() + arr.back());
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;

        ll l = (a+(n-1)) / n;
        ll r = (b+(n-1)) / n;

        ll answ = (r - l - 1) * sum;

        answ += prefix[((l-1) + ((a+(n-1)) % n)) + (n - ((a+(n-1)) % n))] - prefix[(l-1) + ((a+(n-1)) % n)];
        
        answ += prefix[(r-1) + (1 + ((b+(n-1)) % n))] - prefix[r-1];

        cout << answ << endl;
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
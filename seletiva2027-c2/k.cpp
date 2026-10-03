#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<ll> arr(n); for (auto &x : arr) cin >> x;
    vector<ll> prefix(n+1, 0);
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];
    
    while(q--) {
        ll x; cin >> x;

        int i = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();
        ll j = x - prefix[i - 1];

        cout << i << ' ' << j << '\n';
    }
    
    return 0;
}
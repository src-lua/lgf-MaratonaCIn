#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;


int solve() {

    ll n; cin >> n;

    vector<ll> arr(n);
    long long sum = 0ll;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());

    ll answ = (arr[(n+2)/2 - 1] * 2ll * n) - sum + 1ll;

    if (n <= 2) cout << -1 << endl;
    else cout << max(0ll, answ) << endl;

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
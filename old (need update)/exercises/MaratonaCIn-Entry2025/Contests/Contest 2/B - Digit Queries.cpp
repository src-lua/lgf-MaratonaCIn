#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    ll n; cin >> n;

    ll k = 1;
    ll pow10 = 1;

    while(n > 9 * pow10 * k ) {
        n -= 9 * pow10 * k;
        pow10 *= 10;
        k++;
    }

    cout << to_string(pow10 + ((n-1) / k))[((n-1) % k + k) % k] << endl;

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
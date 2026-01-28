#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

ll s(ll n) { return (n * (n - 1) / 2); }

bool f(ll n, ll target) { return s(n) > target; }

// Time Complexity: O(log(n))
ll binarySearch(ll l, ll r, ll target) {
    ll answ;
    while (l <= r) {
        ll m = l + (r - l) / 2;

        // If NOT SOLVE, ignore left half
        if (!f(m, target)) l = m + 1;

        // If SOLVE, ignore right half
        else {
            answ = m;
            r = m - 1;
        }
    }

    return answ - 1;
}

int solve() {
    ll n;
    cin >> n;

    ll k = binarySearch(0, min(ll(1e10), 2 * n + 1), n);

    cout << k - s(k) + n << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
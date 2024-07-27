#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

ll getn(ll k, ll n) { return ((k + n) * (n - k + 1)) / 2ll; }
                                    
int solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<ll> arr;

    int x;

    ll l = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x <= q) {
            l++;
        } else {
            if (l >= k) {
                arr.push_back(l);
            }
            l = 0;
        }
    }

    if (l >= k) {
        arr.push_back(l);
    }
    l = 0;

    ll answ = 0;

    for (auto e : arr) {
        answ += getn(1, e) - getn((e - k + 2), e);
    }

    cout << answ << '\n';

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
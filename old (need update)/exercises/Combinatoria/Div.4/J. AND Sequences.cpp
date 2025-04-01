#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll getfact(ll n) {
    ll answ = 1;

    for (int i = 2; i <= n; i++) {
        answ = (answ * i)  % MOD;
    }
    

    return answ;
}

int solve() {

    int n; cin >> n;

    vector<ll> arr(n);

    map<int,ll> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
    }
    
    int mn;

    for (auto [k, v] : m) {
        if (v < 2) {
            cout << 0 << '\n';
            return 0;
        }

        mn = k;
        break;
    }


    for (auto [k, v] : m) {
        if ((k & mn) != mn) {
            cout << 0 << '\n';
            return 0;
        }
    }

    cout << (((m[mn] * (m[mn]-1)) % MOD) * getfact(n-2)) % MOD << '\n';

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
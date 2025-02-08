#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    ll n, m; cin >> n >> m;

    vector<ll> pos(n+m+1, -1);
    vector<ll> ammount(n+m+1, 0);

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = 0;
    }

    int p, v;
    for (ll i = 1; i <= m; i++) {
        cin >> p >> v;
        p--;

        ammount[arr[p]] += i - pos[arr[p]];
        pos[arr[p]] = -1;
        pos[v] = i;

        arr[p] = v;
    }

    for (int i = 1; i <= n+m; i++) {
        if (pos[i] != -1) {
            ammount[i] += (m+1) -pos[i];
        }
    }

    ll answ = 0;
    ll total = (m * (m+1) ) / 2;

    for (int i = 1; i <= n+m; i++) {
        answ += total - ( ( ( (m-ammount[i]) * (m-ammount[i]+1) )) / 2);
    }

    cout << answ << endl;

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
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

// vector<vector<ll>> dp(1e6+10, vector<ll>(1e6+10, -1));
// ll solve(ll x, ll y) {
//     if (x > y) swap(x,y);
//     if (dp[x][y] != -1) return dp[x][y];

//     return dp[x][y] = x * y + solve(x,y-1) + solve(1, x);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);

    vector<ll> oneansw(x+1);
    oneansw[1] = 1;
    for (ll i = 2; i <= x; i++) {
        oneansw[i] = i + 1ll + oneansw[i-1];
    }

    vector<ll> answ(y+1);
    answ[1] = oneansw[x];
    for (ll i = 2; i <= y; i++) {
        answ[i] = i*x + oneansw[x] + answ[i-1];
    }

    cout << answ[y];

    return 0;
}
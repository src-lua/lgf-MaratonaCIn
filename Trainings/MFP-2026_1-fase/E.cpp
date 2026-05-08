/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/E
 * Status:      AC
 * Created:     07-05-2026 19:05:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using polynomial = vector<ll>;

const int MOD = 1e9+7;
int n;

polynomial operator*(const polynomial& a, const polynomial& b) {
    polynomial ans(n, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            ans[(i+j) % n] = (ans[(i+j) % n] + (a[i] * b[j] % MOD)) % MOD;
        }
    }
    return ans;
}

polynomial pow(polynomial a, ll exp) {
    polynomial ans(n, 0);
    ans[0] = 1; 
    
    while(exp) {
        if(exp & 1) ans = (ans * a);
        a = (a * a);
        exp >>= 1;
    }
    return ans;
}

ll fexpll(ll a, ll n_exp) {
    ll ans = 1;
    while(n_exp) {
        if(n_exp & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        n_exp >>= 1;
    }
    return ans;
}

inline ll inv(ll x) { return fexpll(x, MOD-2); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, k, l; cin >> n >> m >> k >> l;
    vector<int> a(k); for (auto &x : a) cin >> x;
    vector<int> b(l); for (auto &x : b) cin >> x;

    polynomial base(n, 0);
    for (auto front : a) {
        int back = ((n - front) % n + n) % n;
        base[front] = (base[front] + 1) % MOD;
        base[back] = (base[back] + 1) % MOD;
    }

    polynomial ans = pow(base, m);
    
    ll num = 0, dem = 0;
    
    for (auto y : b) num = (num + ans[y]) % MOD;
    for (auto x : ans) dem = (dem + x) % MOD;

    cout << (num * inv(dem)) % MOD << '\n';

    return 0;
}
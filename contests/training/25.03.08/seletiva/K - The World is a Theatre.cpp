#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

// Time complexity: O(n)
vector<ll> fact; 
void precalc_fact(ll n) {
    fact.resize(n+1);

    fact[0] = 1, fact[1] = 1;

    for (ll i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i);
    }
}

ll choose(ll n, ll k) {
    return fact[n] / (f);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t; cin >> n >> m >> t;

    ll answ = 0;

    for (int i = 4; i <= t-1; i++) {
        answ += choose(n, i) * choose(m, t-n);
    }

    cout << answ;
    

    return 0;
}
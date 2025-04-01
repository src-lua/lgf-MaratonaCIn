#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll fact (ll n) {
    ll answ = 1;
    for (int i = 2; i <= n; i++) {
        answ  = (answ * i) % MOD;
    }
    return answ % MOD;
    
}

ll modInverse(ll n) {
    ll ex = MOD-2, result = 1;
    while (ex > 0) {
        if (ex % 2 == 1) {
            result = (result*n) % MOD;
        }
        n = (n*n) % MOD;
        ex /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    ll answ = 0;
    auto a = fact(n + (2*m) - 1);
    auto b = fact(2*m);
    auto c = fact(n-1);
    auto d = (b*c) % MOD;
    auto inv = modInverse(d);


    cout << (a 
    * inv) % MOD << '\n';

    return 0;
}
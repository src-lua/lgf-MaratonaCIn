/**
 * Author:      Lua
 * Problem:     D - Counting Paths
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/D
 * Status:      AC
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll fexpll(ll a, ll n) {
	ll ans = 1;
	while(n) {
		if(n & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return ans;
}

ll modInverse(ll n) {
    return fexpll(n, MOD-2);
}

array<int, (int)1e5+10> fact;

void precalc() {
    fact.fill(-1);

    fact[0] = 1;
    for (ll i = 1; i < 1e5+10; i++) 
        fact[i] = (fact[i-1] * i) % MOD;
}

int solve(int a, int b) {
    return ll(fact[a]) * modInverse(fact[b]) % MOD * modInverse(fact[a-b]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    precalc();

    int tc; cin >> tc;

    for (int i = 0; i < tc; i++) {
        int a, b; cin >> a >> b;
        cout << 2 * solve(a-1, b) % MOD << '\n';
    }

    return 0;
}

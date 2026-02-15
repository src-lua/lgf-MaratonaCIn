/**
 * Author:      Lua
 * Problem:     L - Burgers
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/L
 * Status:      AC
 * Created:     14-02-2026 13:45:39
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

inline ll inv(ll n) {
    return fexpll(n, MOD-2);
}

inline ll getSum(ll n, ll first, ll last) {
    return (first + last) % MOD * n % MOD * inv(2) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m, r, c; cin >> n >> m >> r >> c;
    
    ll x = r%n, y = c%m;
    
    ll k1 = n/gcd(x, n); // k1 linhas por ciclo
    ll k2 = m/gcd(y, m); // k2 colunas por ciclo
    
    // n/k1 == gcd(x,n), pois k1 = n/gcd(x,n)
    ll a = getSum(k1, n-1, n-1-(k1-1)*(n/k1));
    ll b = getSum(k2, m-1, m-1-(k2-1)*(m/k2));

    ll invg = inv(gcd(k1, k2));
    ll A = k2 * invg % MOD; // A ciclos de linha
    ll B = k1 * invg % MOD; // B ciclos de coluna

    // ll steps = lcm(k1, k2)
    // lcm(k1, k2) = k1 * k2 / gcd(k1, k2)
    ll steps = (k1 % MOD) * (k2 % MOD) % MOD * invg % MOD;
    ll K1 = A * a % MOD * m % MOD;
    ll K2 = B * b % MOD;

    cout << (K1 + K2 + steps) % MOD << '\n'; 

    return 0;
}

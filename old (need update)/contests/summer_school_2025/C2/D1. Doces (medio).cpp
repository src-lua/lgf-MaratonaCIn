#include <bits/stdc++.h>

#define endl '\n'

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

// C(n,k+1) = C(n,k) * (n-k) / (k+1)
// Time complexity: O(n*log(mod-2))
vector<int> pascal(int n) {
    vector<int> coefficients(n+1);
    coefficients[0] = 1;

    for (int k = 0; k < n; k++) {
        coefficients[k+1] = (
            ll(( ll(coefficients[k]) * ll(n-k)) % MOD)
             * modInverse(k+1) ) % MOD;
    }

    return coefficients;
}

// Time complexity: O(log(mod-2)*log(n)) [Amortized]
map<int, vector<int>> pascal_triangle;
ll choose(ll n, ll k) {
    if (pascal_triangle.count(n) == 0) pascal_triangle[n] = pascal(n);

    if (k > n || k < 0) return 0;

    return pascal_triangle[n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k; cin >> k >> n;

    ll answ = 0;
    for (int i = 0; i < n; i++) {
        answ = (answ + ((ll(pow(-1, i)) * choose(n, i) * fexpll(n-i, k)) % MOD)) % MOD;
    }

    cout << (answ + MOD) % MOD << endl;
    
    return 0;
}
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;    
using ll = long long;  

const int MOD = 1e9+7;

// Time complexity: O(log(n))
ll fexpll(ll a, ll n) {
	ll ans = 1;
	while(n) {
		if(n & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return ans;
}

// Time complexity: O(log(mod))
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

// O(K) * O(K+log(k)) == O(k²)
int recursion(int n, int k, vector<int>& memoization) {
    if (memoization[k] != -1) return memoization[k];

    // O(log(k));
    ll answ = (fexpll(1+n, k+1) - n - 1 + MOD) % MOD;

    // O(K)
    for (int i = 1; i <= k-1; i++) {
        answ = ((answ - 
                ((choose(k+1, i) * recursion(n, i, memoization)) % MOD)
            ) + MOD) % MOD;
    }

    answ = (answ * modInverse(k+1)) % MOD;

    return memoization[k] = answ;
}

int solve() {
    int n, k; cin >> n >> k;

    vector<int> memoization(k+1, -1);

    cout << recursion(n, k, memoization) << endl;

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
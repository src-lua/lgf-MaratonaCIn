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

// C(n,k+1) = C(n,k) * (n-k) / (k+1)
// Time complexity: O(n)
void pascal(int n, vector<int>& coefficients) {

    coefficients.clear();
    coefficients.push_back(1);

    for (int k = 0; k < n; k++) {
        coefficients.push_back(coefficients[k] * (n-k) / (k+1));
    }
}


int recursion(int n, int k, vector<int>& memoization) {
    if (memoization[k] != -1) return memoization[k];

    ll answ = (fexpll(1+n, k+1) - n - 1) % MOD;

    vector<int> coefficients;
    pascal(k+1, coefficients);

    for (int i = 1; i <= k-1; i++) {
        answ = (((answ - ((coefficients[i] * recursion(n, i, memoization)) % MOD)) % MOD) + MOD) % MOD;
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
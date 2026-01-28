#include <bits/stdc++.h>

#define endl '\n'
const int MOD = 1e9+7;

using namespace std;
using ll = long long;

ll fexpll(ll a, ll n) {
	ll ans = 1;
	while(n) {
		if(n & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    cout << fexpll(2, n);

    return 0;
}
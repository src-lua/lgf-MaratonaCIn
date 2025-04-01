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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    cout << fexpll(2, n-1) << endl;

    return 0;
}
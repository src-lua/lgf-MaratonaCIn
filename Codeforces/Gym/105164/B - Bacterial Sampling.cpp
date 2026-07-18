#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long int;

const int MOD = 1e9+7;

ll fexpll(ll a, ll n) {
    if (n<=0) return 0; 
    
    ll answ = 1;
    while(n) {
        if (n & 1) answ = (answ *a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return answ;
}

int solve() {

    int n; cin >> n;

    ll sum = 1;

    if (n%6 < 2) sum += 4 * fexpll(3, n/6-2);

    sum = (sum + 2 * fexpll(3, n/6 -1))%MOD;
    sum = (sum + fexpll(3, n/6))%MOD;

    int k = n%6;

    if (k >= 2) {
        sum = (sum + fexpll(3, n/6 -1))%MOD; 
    }

    if (k >= 4) {
        sum = (sum + fexpll(3, n/6))%MOD;
    }
    
    cout << sum << '\n';

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
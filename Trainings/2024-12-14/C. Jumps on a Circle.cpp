#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int MOD;

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

    int p, n; cin >> p >> n;
    MOD = p;

    vector<int> ss;

    ll prev = 0;

    for (ll i = 1; i <= min(p+10, n); i++) {
        ss.push_back(prev);
        prev = (prev + (i % MOD)) % MOD;
    }
    ss.push_back(prev);

    std::sort(ss.begin(), ss.end());
    auto answ = std::unique(ss.begin(), ss.end()) - ss.begin();
    cout << answ << endl;
    
    return 0;
}
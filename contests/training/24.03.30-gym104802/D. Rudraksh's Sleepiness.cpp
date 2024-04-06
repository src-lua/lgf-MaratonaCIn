#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

vector<ll> prime_list;

void SieveOfEratosthenes(ll n)
{
    vector<bool> prime(n + 1, true);
 
    for (ll p = 2; p <= n; p++) {
        if (prime[p] == true) {
            prime_list.push_back(p);

            for (ll i = p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int solve() {

    int x, y; cin >> x >> y;

    int distance = x + y;

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    SieveOfEratosthenes(1e7);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
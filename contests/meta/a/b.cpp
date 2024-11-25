#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

vector<ll> prime_list;

// Time Complexity: O(n log log n)
void EratosthenesSieve(ll n) {
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

    int n; cin >> n;

    ll answ = 0;

    if (n >= 5) answ++;

    for (int i = 1; i < prime_list.size(); i++) {
        if (prime_list[i] > n) break;
        
        if (prime_list[i] == prime_list[i-1]+2) {
            answ++;
        }
    }

    cout << answ << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int c = 0;

    EratosthenesSieve(10000000);

    int tc; cin >> tc; while (tc--) {
        cout << "Case #" << ++c << ": "; 
        solve();
    }

    return 0;
}
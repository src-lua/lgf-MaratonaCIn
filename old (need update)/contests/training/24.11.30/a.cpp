#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

vector<ll> prime_list;
using pll = pair<ll,ll>;

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

vector<pll> prime_factorization(ll n) {
    vector<pll> answ;

    for (auto e : prime_list) {
        if (n % e == 0) {
            answ.push_back({e, 1});
            n /= e;
        }
        while (n % e == 0) {
            answ.back().second++;
            n /= e;
        }
    }

    return answ;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    EratosthenesSieve(1e6);

    int n; cin >> n;
    
    vector<pll> factorization = prime_factorization(n);

    ll a = 1, b = 1;
    int i = 0;

    for (auto [p, q] : factorization) {
        if (q/2 != 0) {
            a *=  p * (q/2);
            b *=  p * (q/2);
        }

        if (q % 2 == 1) {
            if (a < b) a *= p;
            else b *= p;
        }
    }

    cout << a+b-2 << endl;

    return 0;
}
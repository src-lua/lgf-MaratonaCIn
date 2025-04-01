#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

vector<ll> prime_list;
vector<bool> prime;

// Time Complexity: O(n log log n)
void EratosthenesSieve(ll n) {
    
    prime = vector<bool>(n + 1, true);
    for (ll p = 2; p <= n; p++) {
        if (prime[p] == true) {
            prime_list.push_back(p);

            for (ll i = p+p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    EratosthenesSieve(1e6);

    int n, k; cin >> n >> k;

    int c = 0;
    for (int i = 0; i < prime_list.size() && prime_list[i]+prime_list[i+1]+1 <= n; i++) {
        if (prime[prime_list[i] + prime_list[i+1] + 1]) c++;
    }

    if (c >= k) cout << "YES\n";
    else cout <<"NO\n";    
    
    return 0;
}
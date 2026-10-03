#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// suponha que ela botou doces p vezes, logo
// 1 + 2 + 3 + ... + p == p(p+1)/2
// se ela botou doces p vezes, ela comeu (n-p)
// portanto, p(p+1)/2 - (n - p) = k
// DESEVOLVENDO:
// p² + p + 2p = 2(n + k)
// p² + 3p - 2(n + k) = 0
// RESOLVENDO:
// p = (-3 + sqrt(9 + 8(n + k))) / 2 
// note que pegamos só o + porq queremos uma raiz positiva
// como queremos saber quantos ela comeu, printe n - p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k; cin >> n >> k;

    ll d = 9 + 8 * (n + k);
    ll s = (ll) sqrtl((long double) d);
    
    while (s * s > d) s--;
    while ((s + 1) * (s + 1) <= d) s++;

    ll p = (s - 3) / 2;
    cout << n - p << '\n';

    return 0;
}
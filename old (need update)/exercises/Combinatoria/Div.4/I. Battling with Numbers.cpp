// LCM => máximo dos expoentes dos primos
// GCD => mínimo dos expoentes dos primos

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 998244353;

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

    set<int> primes;
    int k;

    int n; cin >> n;

    vector<int> xprimes(n);
    map<int,int> xfreq;

    for (int i = 0; i < n; i++) {
        cin >> xprimes[i];
        primes.insert(xprimes[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> k;
        xfreq[xprimes[i]] = k;
    }

    int m; cin >> m;

    vector<int> yprimes(m);
    map<int,int> yfreq;

    for (int i = 0; i < m; i++) {
        cin >> yprimes[i];
        primes.insert(yprimes[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> k;
        yfreq[yprimes[i]] = k;
    }

    bool hasansw = true;
    int answ = 0;

    for (auto p : primes) {
        // Se o expoente do LCM for menor que o do GCD, não tem resposta.
        // Se o expoente for igual, a resposta é multiplicada por 1, pois só
        //      existe uma possibilidade: p e q tem expoente igual.
        // Se o expoente do LCM for maior que o do GCD, então a resposta é
        //      multiplicada por 2, pois p pode ter o expoente maior ou o menor. 

        if (xfreq[p] < yfreq[p]) {// Se o maior expoente for menor que o menor expoente
            hasansw = false;
            break;
        } else if (xfreq[p] > yfreq[p]) { answ++; }
    }

    answ = fexpll(2, answ);
    
    if (!hasansw) {
        cout << 0 << '\n';
    } else {
        cout << answ << '\n';
    }

    return 0;
}
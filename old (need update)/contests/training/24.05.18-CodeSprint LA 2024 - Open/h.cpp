#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

ll gcd(ll m, ll n) {

    ll r;

    if (m < n) {
        r = m; 
        m = n; 
        n = r;
    }

    while(n != 0) {
        r = m%n;

        m=n; n=r;
    }

    return m;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(12) << fixed;


    int n, m, l; cin >> n >> m >> l;

    ll lg = log2(n)*10000;

    ll answ = 2e10/lg;


    cout << lg;

    return 0;
}
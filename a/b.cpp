#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, d, m, l;
    cin >> n >> d >> m >> l;

    ll i;
    for (i = 0; i*d < (n-1)*m+l+1; i++) {
        ll k = i*d;

        ll p = k / m;
        if (p * m + l < k) {
            cout << k << endl;
            return 0;
        }

        i = (p*m+l+d) / d - 1;
    }

    cout << i*d << endl;

    return 0;
}
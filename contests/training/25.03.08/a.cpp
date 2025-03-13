#include <bits/stdc++.h>

#define endl '\n'
using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y, k;
    cin >> x >> y >> k;

    cout << ((x+k-1)/k) * ((y+k-1)/k); 

    return 0;
}
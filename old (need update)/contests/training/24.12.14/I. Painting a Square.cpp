#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b; cin >> a >> b;

    ll answ = a-b;

    ll k = 1;
    while (a - (k * b) > 0) {
        answ += 2*(a-k*b);
        k++;
    }

    cout << answ;

    return 0;
}
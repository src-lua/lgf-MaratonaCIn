#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

vector<ll> store_fib(1e6, -1);
ll fib(ll n) {
    if (store_fib[n] != -1) return store_fib[n];

    return store_fib[n] = fib(n-1) + fib(n-2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    store_fib[0] = 1;
    store_fib[1] = 1;

    int n; cin >> n;

    cout << fib(n) << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    const int M = 200000;
    vector<ll> cnt(M + 2, 0);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
        mx = max(mx, a);
    }

    vector<ll> c(mx, 0); // c[j] = quantidade de A_i > j
    ll suffix = 0;
    for (int j = mx - 1; j >= 0; j--) {
        suffix += cnt[j + 1];      // soma dos cnt[k] com k >= j+1
        c[j] = suffix;
    }

    // soma com carry, do dígito menos significativo para o mais
    string res;
    ll carry = 0;
    for (int j = 0; j < mx; j++) {
        ll total = c[j] + carry;
        res.push_back('0' + total % 10);
        carry = total / 10;
    }
    while (carry > 0) {
        res.push_back('0' + carry % 10);
        carry /= 10;
    }

    reverse(res.begin(), res.end());
    cout << res << '\n';
    return 0;
}
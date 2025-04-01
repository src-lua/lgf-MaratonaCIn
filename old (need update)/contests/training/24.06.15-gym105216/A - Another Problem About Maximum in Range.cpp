#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

vector<vector<ll>> table;
vector<ll> lg2;

const int MOD = 1e9 + 7;

void build(int n, vector<ll> v) {
    lg2.resize(n + 1);
    lg2[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
    table.resize(lg2[n] + 1);
    for (int i = 0; i < lg2[n] + 1; i++) {
        table[i].resize(n + 1);
    }
    for (int i = 0; i < n; i++) {
        table[0][i] = v[i];
    }
    for (int i = 0; i < lg2[n]; i++) {
        for (int j = 0; j < n; j++) {
            if (j + (1 << i) >= n) break;
            table[i + 1][j] = max(table[i][j], table[i][j + (1 << i)]);
        }
    }
}

ll get(int l, int r) {  // (l, r) inclusivo
    int k = lg2[r - l + 1];
    return max(table[k][l], table[k][r - (1 << k) + 1]);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    int d = gcd(b, a % b);
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(n, arr);

    ll answ = 0;
    ll g;
    ll q;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            g = gcd(j,i);
            q = get(i - 1, j - 1);
            answ += (q * (g * g % MOD)) % MOD;
        }
    }

    cout << answ % MOD << '\n';

    return 0;
}
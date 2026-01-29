/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://vjudge.net/contest/782309#problem/L
 * Status:      WA
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
#define iii array<ll, 3>
using namespace std;

const int MAXN = 100000 + 10;
int pai[MAXN];

int find(int u) { return pai[u] = pai[u] == u ? u : find(pai[u]); }

void join(int u, int v) {
    u = find(u);
    v = find(v);
    pai[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) pai[i] = i;

    vector<iii> arestas;
    vector<int> ponta(n, 2);

    for (int u = 0, v, c; u < n; u++) {
        cin >> v >> c;
        v--;
        arestas.push_back({c, u, v});
    }

    sort(rbegin(arestas), rend(arestas));
    ll ans = 0;

    for (auto [c, u, v] : arestas) {
        if (ponta[u] && ponta[v] && find(u) != find(v)) {
            ans += c;
            ponta[u]--;
            ponta[v]--;
            join(u, v);
        }
    }

    cout << ans << endl;
}
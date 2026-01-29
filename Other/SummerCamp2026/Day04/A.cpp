/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://vjudge.net/contest/783478#problem/A
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

ll dijkstra(vector<vector<pii>>& adj, int start) {
    vector<ll> dist(adj.size(), LLONG_MAX);

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, start); dist[start] = 0;

    while(!pq.empty()) {
        auto [w_u, u] = pq.top(); pq.pop();

        if (dist[u] != w_u) continue;

        for (auto [w_v, v] : adj[u]) {
            if (w_v + w_u < dist[v]) {
                dist[v] = w_v + w_u;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n+n);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;

        adj[u].emplace_back(w,v);
        adj[u].emplace_back(w/2,n+v);
        adj[n+u].emplace_back(w, n+v);
    }

    for (int i = 0; i < n; i++) adj[i].emplace_back(0, n+i);

    cout << dijkstra(adj, 0) << '\n';

    return 0;
}
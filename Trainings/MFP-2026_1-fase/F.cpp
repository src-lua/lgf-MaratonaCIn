/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/F
 * Status:      AC
 * Created:     07-05-2026 19:05:05
 **/

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int dijkstra(vector<vector<pii>>& adj, int start, int end) {
    vector<int> dist(adj.size(), -1); dist[start] = INT_MAX;
    priority_queue<pii> pq; pq.emplace(dist[start], start);

    while(!pq.empty()) {
        auto [_, u] = pq.top(); pq.pop();

        for(auto [w , v] : adj[u]) {
            if (dist[v] >= min(dist[u], w)) continue;
            dist[v] = min(dist[u], w);
            pq.emplace(dist[v], v);
        }
    }

    return dist[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, s, t; cin >> n >> m >> s >> t; s--, t--;
    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].emplace_back(w, v);
    }
    
    cout << dijkstra(adj, s, t) << '\n';

    return 0;
}

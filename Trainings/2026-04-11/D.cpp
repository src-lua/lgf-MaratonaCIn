/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/D
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;

void bfs(vector<vector<pii>>& adj, vector<ll>& dist, int root) {
    queue<int> q; q.push(root); dist[root] = 0;
    vector<int> visited(adj.size(), INT_MAX); visited[root] = 1;

    while(!q.empty()) {
        auto u = q.front(); q.pop(); 

        for (auto [v, w] : adj[u]) {
            if (visited[v] < visited[u]+1) continue;
            visited[v] = visited[u] + 1;

            dist[v] = min(dist[v], ll(visited[v]-1) * w);
            q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i =0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<ll> dist(n, LLONG_MAX);
    bfs(adj, dist, 0);

    cout << accumulate(dist.begin(), dist.end(), 0LL);

    return 0;
}

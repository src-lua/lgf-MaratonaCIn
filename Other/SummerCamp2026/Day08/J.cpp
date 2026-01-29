/**
 * Author:      Lua
 * Problem:     J
 * Link:        https://vjudge.net/contest/784977#problem/J
 * Status:      AC
 * Created:     28-01-2026 16:28:16
 **/

#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>>& adj, vector<int>& parent, int start) {
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    q.push(start); dist[start] = 0;

    int mx = 0;
    int mx_idx = start;

    while(!q.empty()) {
        auto u = q.front(); q.pop();

        if (dist[u] > mx) {
            mx = dist[u];
            mx_idx = u;
        }
    
        for (auto v : adj[u]) {
            if (dist[v] != -1) continue;

            dist[v] = dist[u] + 1;
            parent[v] = u;
            q.push(v);
        }
    }

    return mx_idx;
}

pair<int,int> bfs_multisource(vector<vector<int>>& adj, vector<int>& sources) {
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    for (auto start : sources)
        q.push(start), dist[start] = 0;

    int mx = 0;
    int mx_idx = -1;

    while(!q.empty()) {
        auto u = q.front(); q.pop();

        if (dist[u] > mx) {
            mx = dist[u];
            mx_idx = u;
        }
    
        for (auto v : adj[u]) {
            if (dist[v] != -1) continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return {mx_idx, mx};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    vector<int> parent(n, -1);
    auto leaf1 = bfs(adj, parent, 0);

    parent = vector<int>(n, -1);

    auto leaf2 = bfs(adj, parent, leaf1);

    vector<int> path;

    int u = leaf2;
    while(u != -1) {
        path.push_back(u);
        u = parent[u];
    }

    auto [leaf3, dist] = bfs_multisource(adj, path);
    if (leaf3 == -1) leaf3 = path[1];

    cout << dist + path.size() - 1 << '\n';
    cout << leaf1 + 1 << ' ' << leaf2 + 1 << ' ' << leaf3 + 1 << '\n';

    return 0;
}
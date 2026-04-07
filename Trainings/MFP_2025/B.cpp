/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/606592/problem/B
 * Status:      AC
 * Created:     06-04-2026 21:45:52
 **/

#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start); 
    visited[start] = true;

    while(!q.empty()) {
        auto u = q.front(); q.pop();

        for (auto v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("B_3.in", "r", stdin);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> degree(n);

    int root = -1; // testar grafo unitario
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int components = 0;

    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            bfs(adj, visited, u);
            components++;
        }
    }

    int build = components - 1;
    int destroy = (m+build) - (n-1);

    if (build == 0 && destroy == 0) cout << "BOM\n";
    else cout << "RUIM "<< destroy << ' ' << build << '\n';

    return 0;
}

/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://codeforces.com/gym/101492/problem/A
 * Status:      ~
 * Created:     01-05-2026 09:34:33
 **/

#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& dist, int start) {
    stack<pair<int,int>> q;
    q.emplace(start, start);
    dist[start] = -1;
    
    while (!q.empty()) {
        auto [u, p] = q.top(); q.pop();
        if (dist[u] != -1) continue;
        dist[u] = dist[p] + 1;


        for (auto v : adj[u]) {
            if (dist[v] != -1) continue;
            q.emplace(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n, -1);
    for (int i = 0; i < n; i++) {
        if (dist[i] == -1) dfs(adj, dist, i);
    }

    auto color = [&](int u) {
        return dist[u] % k + 1;
    };

    for (int u = 0; u < n; u++) {
        for (auto v : adj[u]) if (color(u) == color(v)) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int u = 0; u < n; u++) cout << color(u) << '\n'; 

    return 0;
}

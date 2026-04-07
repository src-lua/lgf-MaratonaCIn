/**
 * Author:      Lua
 * Problem:     A - Avoiding the Apocalypse
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101512/problem/A
 * Status:      ~
 * Created:     21-03-2026 09:04:56
 **/

#include <bits/stdc++.h>

#define vec vector

using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

int pass[1001][1001][101];

set<tuple<int,int,int>> to_clean; 

bool dijkstra(
    vec<vec<ii>>& adj,
    vec<int>& is_med,
    int start,
    int steps
) {
    int n = adj.size();
    
    priority_queue<ii, vec<ii>, greater<> > pq;

    pq.emplace(0, start);

    vec<int> parent(n, -1); parent[start] = start; 
    vec<int> dist(n, INT_MAX); dist[start] = 0;
    vec<bool> visited(n, false);

    while(!pq.empty()) {
        auto [_, u] = pq.top();
        if (is_med[u]) break;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (visited[v]) continue;
            auto [w, k] = adj[u][v]; 
            
            int i = 0; while (pass[u][v][dist[u]+i++] == k) w++;

            if (dist[v] <= dist[u] + w) continue;
            dist[v] = dist[u] + w; parent[v] = u;

            pq.emplace(dist[v], v);
        }
    }

    if (pq.empty()) return false;
    int u = pq.top().second;

    if (dist[u] > steps) return false;

    while (parent[u] != u) {
        auto pu = parent[u]; auto k = adj[pu][u].second;
        int i = 0; while (pass[pu][u][dist[pu]+i] == k) i++;
        ++pass[pu][u][dist[pu]+i];
        to_clean.emplace(pu,u, dist[pu]+i);
        u = pu;
    }

    return true;
}

void solve() {
    int n; cin >> n;
    int s, p, t; cin >> s >> p >> t; s--;

    int m; cin >> m; vec<int> med(m); 
    for (auto &x : med) cin >> x;

    vec<int> is_med(n, false);
    for (auto &i : med) is_med[i-1] = true;

    int r; cin >> r; vec<vec<ii>> adj(n, vec<ii>(n));
    for (int i = 0; i < r; i++) {
        int u, v, k, w; cin >> u >> v >> k >> w; u--, v--;
        adj[u][v] = {w, k};
    }

    int ans = 0;
    // O(p * dijkstra) ≈ 1e2 * 1e4 ≈ 1e6 
    for (int i = 0; i < p; i++) {  

        // O(r \log v) ≈ 1e4
        if (dijkstra(adj, is_med, s, t)) ans++;
        else break;
    }
    
    cout << ans << '\n';

    for (auto [i,j,k] : to_clean) pass[i][j][k] = 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) {
        solve(); 
        if (tc) to_clean.clear();
    }

    return 0;
}

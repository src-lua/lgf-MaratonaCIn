#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

// Time Complexity: O((V + E) * log(V))
void dijkstra(vector<vector<pii>>& adj, vector<ll>& dist, vector<bool>& visited, int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [w, v]: adj[u]) {
            if (visited[v]) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<pii>> adj(2*n+1);

    int x, y, w;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;

        adj[x].push_back({w, y});
        adj[n+x].push_back({w/2, y});
        adj[n+x].push_back({w, n+y});
    }

    vector<ll> dist(2*n+1, LLONG_MAX);
    vector<bool> visited(2*n+1, false);

    dijkstra(adj, dist, visited, n+1);

    cout << dist[n] << endl;
    
    return 0;
}
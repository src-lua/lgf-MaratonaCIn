#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;
using pipii = pair<int,pii>;

// Time Complexity: O((V + E) * log(V))
void prim(vector<vector<pii>>& adj, vector<bool>& visited, vector<int>& dist, vector<int>& parent) {
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    pq.push({0, {0,0}});
    dist[0] = 0;

    while (!pq.empty()) {
        auto [v, u] = pq.top().second;
        pq.pop();

        if (visited[v]) continue;
        visited[v] = true;
        parent[v] = u;

        for (auto [w, e]: adj[v]) {
            if (dist[v] > w) {
                dist[v] = w;
                pq.push({dist[v], {v, e} });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);

    int a, b, w;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> w;
        a--; b--;

        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    vector<bool> visited(n, false);
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    prim(adj, visited, dist, parent);
    
    cout << 1;

    return 0;
}
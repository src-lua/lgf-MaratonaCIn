#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

// Time Complexity: O((V + E) * log(V))
void prim(vector<vector<pii>>& adj, vector<int>& dist, vector<bool>& visited, int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, w]: adj[u]) {
            if (visited[v]) continue;
            if (dist[v] > w) {
                dist[v] = w;
                pq.push({dist[v], v, });
            }
        }
    }
}

int solve() {

    int n, m, a; cin >> n >> m >> a;

    vector<vector<pii>> adj(n);

    int x, y, c;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        x--, y--;

        if (c < a) {
            adj[x].push_back({y, c});
            adj[y].push_back({x, c});
        }
    }

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    int airports = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            airports++;
            prim(adj, dist, visited, i);
        }
    }

    int cost = 0;
    for (auto e : dist) cost += e;

    cout << a * airports + cost << ' ' << airports << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc; cin >> tc; while (tc--) {
        cout << "Case #" << ++c << ": "; 
        solve();
    }

    return 0;
}
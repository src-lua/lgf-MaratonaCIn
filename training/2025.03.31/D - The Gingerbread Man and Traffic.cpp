/*
Lucas Guimarães Fernandes </lgf_cin>
MaratonaCIn @ CIn - UFPE

[The Gingerbread Man and Traffic](https://codeforces.com/gym/105741/problem/D)
Rating: NOT DEFINED
Tags: 

Date: 2025-04-01
Status: Upsolved
*/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

void dijkstra(int start, vector<vector<pii>>& adj, vector<pii>& semaphores, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            auto [red, green] = semaphores[u];
            int wait_time = d % (red + green) >= red ? (green - (d% (red + green) - red)) : 0;

            int new_dist = d + w + wait_time;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);
    vector<pii> semaphores(n);

    for (int i = 0; i < n; i++) {
        cin >> semaphores[i].first >> semaphores[i].second;
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u-1].push_back({v-1, w});
        adj[v-1].push_back({u-1, w});
    }
    
    vector<int> dist(adj.size(), INT_MAX);

    dijkstra(0, adj, semaphores, dist);
    cout << dist[n-1] << endl;

    return 0;
}

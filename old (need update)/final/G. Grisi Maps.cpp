#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long int;
using pii = pair<ll,ll>;

// Time Complexity: O((V + E) * log(V))
void dijkstra(vector<vector<pii>>& adj, vector<ll>& dist, ll s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        for (auto e: adj[u]) {
            ll v = e.first;
            ll w = e.second;

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

    ll n, m, q, unicamp, ic;
    cin >> n >> m >> q >> unicamp >> ic;
    unicamp--, ic--;

    vector<vector<pii>> adj(n);

    ll u, v, w;
    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> distUnicamp(n, LLONG_MAX);
    vector<ll> distIC(n, LLONG_MAX);

    dijkstra(adj, distUnicamp, unicamp);
    dijkstra(adj, distIC, ic);

    
    for (ll i = 0; i < q; i++) {
        cin >> v; v--;

        cout << ( distIC[unicamp] + distUnicamp[v] ) - distIC[v] << endl;
    }
    

    return 0;
}
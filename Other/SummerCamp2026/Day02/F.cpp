/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://vjudge.net/contest/782309#problem/F
 * Status:      AC
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;
using iii = tuple<int,int,int>;

int getdist(vector<vector<int>>& adj, int start) {
    queue<int> q;

    vector<int> dist(adj.size(), INT_MAX);
    
    dist[start] = 0;
    q.push(start);

    int max_dist = 0;
    int max_idx = start;

    while(!q.empty()) {
        auto top = q.front(); q.pop();

        for (auto e : adj[top]) {
            if (dist[e] != INT_MAX) continue;
            dist[e] = dist[top] + 1;
            if (max_dist < dist[e]) {
                max_dist = dist[e];
                max_idx = e;
            }
            q.push(e);
        }
    }

    return max_idx;
}

iii diameter(vector<vector<int>>& adj, int start) {
    queue<int> q;

    vector<int> dist(adj.size(), INT_MAX);
    vector<int> parent(adj.size(), -1);

    dist[start] = 0;
    q.push(start);

    int max_dist = 0;
    int max_idx = start;

    while (!q.empty()) {
        auto top = q.front(); q.pop();

        for (auto e : adj[top]) {
            if (dist[e] != INT_MAX) continue;
            dist[e] = dist[top] + 1;
            if (max_dist < dist[e]) {
                max_dist = dist[e];
                max_idx = e;
            }
            parent[e] = top;
            q.push(e);
        }
    }

    int ans = max_idx;
    for (int i = 0; i < max_dist/2; i++) {
        ans = parent[ans];
    }

    int ans2 = parent[ans];

    return {
        ans, (max_dist % 2 ? ans2 : ans), max_dist
    };
}

int solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto [mid1, mid2, dist] = diameter(adj, getdist(adj, 0));

    if (dist % 2) {
        cout << (dist+3)/4 * 2 << '\n';
        for (int i = 1; i <= (dist+1)/2; i+=2) {
            cout << mid1+1 << ' ' << i << '\n';
            cout << mid2+1 << ' ' << i << '\n';
        }
    }
    
    else {
        cout << (dist+1)/2+1 << '\n';
        for (int i = 0; i <= (dist+1)/2; i++) {
            cout << mid1+1 << ' ' << i << '\n';
        }
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    int tc; cin >> tc;
     while(tc--) solve();

    return 0;
}
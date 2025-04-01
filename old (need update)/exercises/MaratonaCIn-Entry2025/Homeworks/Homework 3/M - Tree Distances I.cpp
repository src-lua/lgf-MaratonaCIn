#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int max_dist = 0;
int last = -1;

// Time Complexity: O(V + E)
void bfs(vector<vector<int>>& adj, vector<int>& dist, int start) {
    queue<pii> operation_order;

    dist[start] = 0;
    operation_order.push({start, 0});

    while (!operation_order.empty()) {
        auto [top, d] = operation_order.front();
        operation_order.pop();
        last = top;

        for (auto e : adj[top]) {
            if (dist[e] == -1) {
                dist[e] = d+1;
                max_dist = max(max_dist, d+1);
                operation_order.push({e, d+1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n);

    int x, y;

    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        x--; y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n, -1);
    bfs(adj, dist, 0);
    
    vector<int> dist1(n, -1);
    bfs(adj, dist1, last);
    
    vector<int> dist2(n, -1);
    bfs(adj, dist2, last);

    for (int i = 0; i < n; i++) {
        cout << max(dist1[i], dist2[i]) << ' ';
    }

    return 0;
}   
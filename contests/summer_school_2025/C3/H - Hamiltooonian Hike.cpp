#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int m; cin >> m;

    vector<vector<int>> adj(n);

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<set<int>> graph(n);

    for (int i = 0; i < n; i++) {
        for (auto e : adj[i]) { // Caminhos de tam 1
            graph[i].insert(e);

            for (auto l : adj[e]) { // Caminhos de tam 2
                graph[i].insert(l);
            
                for (auto j : adj[l]) { // Caminhos de tam 3
                    graph[i].insert(j);
            
                }
            }
        }
    }
    


    

    return 0;
}
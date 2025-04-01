#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

// Time Complexity: O(V + E)
void bfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& answ, int start) {
    queue<int> operation_order;

    visited[start] = true;
    operation_order.push(start);

    while (!operation_order.empty()) {
        auto top = operation_order.front();
        operation_order.pop();

        for (auto e : adj[top]) {
            if (!visited[e] && e < start) {
                visited[e] = true;
                operation_order.push(e);
                if (answ[e] == -1) answ[e] = start;
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
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(auto &e : adj) sort(e.begin(), e.end());

    vector<int> answ(n, -1);
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        bfs(adj, visited, answ, i);
    }

    for (auto e : answ) {
        if (e == -1) cout << n << ' '; 
        else cout << e + 1<< ' ';
    }

    cout << endl;

    return 0;
}
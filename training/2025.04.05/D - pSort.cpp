#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void bfs(vector<vector<int>>& adj, vector<int>& visited, int start, int mark) {
    queue<int> operation_order;

    visited[start] = mark;
    operation_order.push(start);

    while (!operation_order.empty()) {
        auto top = operation_order.front();
        operation_order.pop();

        for (auto e : adj[top]) {
            if (!visited[e]) {
                visited[e] = mark;
                operation_order.push(e);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i]--;
        if (i+x < n) {
            adj[i].push_back(i+x);
            adj[i+x].push_back(i); 
        }
        if (i-x >= 0) {
            adj[i].push_back(i-x);
            adj[i-x].push_back(i); 
        }
    }

    int mark = 1;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) bfs(adj, visited, i, mark++);
    }

    for (int i = 0; i < n; i++) {
        if (visited[arr[i]] != visited[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    return 0;
}
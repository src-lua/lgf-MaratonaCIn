#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int max_depth = 0;

// Time Complexity: O(V + E)
void bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
    queue<pii> operation_order;

    visited[start] = true;
    operation_order.push({start, 1});

    while (!operation_order.empty()) {
        auto [top, depth] = operation_order.front();
        max_depth = max(max_depth, depth);
        operation_order.pop();

        for (auto e : adj[top]) {
            if (!visited[e]) {
                visited[e] = true;
                operation_order.push({e, depth+1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> sons(n);
    vector<int> starts;


    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == -1) starts.push_back(i);
        else {
            sons[x-1].push_back(i);
        }
    }

    vector<bool> visited(n, false);
    for (auto s : starts) {
        bfs(sons, visited, s);
    }

    cout << max_depth << '\n';
    

    return 0;
}
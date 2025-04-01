#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

// Time Complexity: O(V + E)
int bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
    int answ = 0;
    queue<int> operation_order;

    visited[start] = true;
    operation_order.push(start);

    while (!operation_order.empty()) {
        answ++;
        auto top = operation_order.front();
        operation_order.pop();

        for (auto e : adj[top]) {
            if (!visited[e]) {
                visited[e] = true;
                operation_order.push(e);
            }
        }
    }
    return answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> answ;
    int dont_care = 0;

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int k = bfs(adj, visited, i);
            if (k == 1) dont_care++;
            else answ.push_back(k);
        }
    }

    string s(5, '0');
    
    for (auto e : answ) {
        for (int i = 0; i <= dont_care; i++) {
            s[e+i-1] = '1';
        }
    }
    s[0] = '1';

    cout << s << endl;

    return 0;
}
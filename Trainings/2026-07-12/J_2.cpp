/**
 * Author:      Lua
 * Problem:     J
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103049/problem/J
 * Status:      ~
 * Created:     12-07-2026 09:01:59
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> path;
    int w_count = n;
    int b_count = 0;

     

    int mole_size = b_count; 
    
    cout << path.size() << ' ' << mole_size << '\n';

    vector<bool> in_path(n, false);
    for (int u : path) {
        in_path[u] = true;
        cout << u + 1 << ' ';
    } cout << '\n';

    for (int u = 0; u < n; u++) if (visited[u] && !in_path[u]) {
        cout << u + 1 << ' ';
    } cout << '\n';
    
    for (int i = 0; i < n; i++) if (!visited[i]) {
        cout << i + 1 << ' ';
    } cout << '\n';

    return 0;
}
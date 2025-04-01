/*                                          
  Lucas Guimarães Fernandes </lgf_cin>
  MaratonaCIn @ CIn - UFPE

  [Remove Exactaly Two](https://codeforces.com/contest/2063/problem/C)
  Rating: 1600
  Tags: Graph; Tree; Greedy;
  Status: Accepted
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

// Time Complexity: O(V + E)
void bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
    queue<int> operation_order;

    visited[start] = true;
    operation_order.push(start);

    while (!operation_order.empty()) {
        auto top = operation_order.front();
        operation_order.pop();

        for (auto e : adj[top]) {
            if (!visited[e]) {
                visited[e] = true;
                operation_order.push(e);
            }
        }
    }
}

int solve() {
    int n; cin >> n;

    vector<vector<int>> adj(n);

    map<int, int> inDegree;

    int x, y;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y; 
        x--, y--;

        adj[x].push_back(y);
        adj[y].push_back(x);

        inDegree[x]++;
        inDegree[y]++;
    }

    int mx = 0;
    vector<int> mx_idx;
    
    for (auto [k,v] : inDegree) {
        if (mx == v) {
            mx_idx.push_back(k);
        }
        if (mx < v) {
            mx = v;
            mx_idx = {k};
        }
    }

    int c = 0;
    //  mx + mx2 -1;

    for (int i = 0; i < min(2ull, mx_idx.size()); i++) {
        for (auto e : adj[mx_idx[i]]) {
            inDegree[e]--;
        }
        
        int mx2 = 0;
        int mx2_idx = -1;
        for (auto [k,v] : inDegree) {
            if (k == mx_idx[i]) continue;
            if (mx2 <= v) {
                mx2 = v;
                mx2_idx = k;
            }
        }

        c = max(c, mx+mx2-1);
        
        for (auto e : adj[mx_idx[i]]) {
            inDegree[e]++;
        }
    }
    
    cout << c << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
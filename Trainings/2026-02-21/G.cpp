/**
 * Author:      Lua
 * Problem:     G - Robots
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/G
 * Status:      AC
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<vector<pair<int,int>>>& adj, vector<pair<int,int>>& queries, vector<int>& ans, int& idx, int val, int p) {
    if (idx >= ans.size()) return;

    sort(adj[u].rbegin(), adj[u].rend());
    for (auto [w, v] : adj[u]) { 
        if (v == p) continue;
        if (queries[idx].first > w) 
            dfs(v, adj, queries, ans, idx, max(val, w), u);
        if (idx >= ans.size()) return;
    }

    while (idx < ans.size() && queries[idx].first > val) {
        ans[queries[idx].second] = u + 1;
        idx++;
    }
}

void solve() {
    int n, q; cin >> n >> q;

    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    

    vector<pair<int,int>> queries(q); int c = 0;
    for (auto &[x, i] : queries) cin >> x, i = c++;
    sort(queries.rbegin(), queries.rend());
    
    vector<int> ans(q, 0);

    int idx = 0; dfs(0, adj, queries, ans, idx, -1, -1);

    // cout << "DBG: "; for (auto e : ans) cout << e << ' '; cout << '\n';
    cout << accumulate(ans.begin(), ans.end(), 0LL) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}

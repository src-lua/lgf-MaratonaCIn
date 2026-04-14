/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/A
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

using pii = pair<int,int>;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<vector<pii>> adj(n+1);
    adj[0].emplace_back(1, 1);
    vector<int> indegree(n+1, 0);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        indegree[v]++;
    }

    vector<ll> cost(n+1, 0);
    queue<int> q; q.push(0); indegree[1]++;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, w]: adj[u]) {
            cost[v] += cost[u] + w;
            if (--indegree[v] == 0) q.push(v);
        }
    }
    
    vector<ll> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] > 0 || cost[i] <= 0 || cost[i] > k) continue;
        
        for (int w = cost[i]; w <= k; w++) {
            dp[w] = (dp[w] + dp[w - cost[i]]) % MOD;
        }
    }

    ll ans = 0;
    for (int w = 1; w <= k; w++) {
        ans = (ans + dp[w]) % MOD;
    }

    cout << ans << '\n';
}
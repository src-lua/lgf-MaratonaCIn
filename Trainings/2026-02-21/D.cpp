/**
 * Author:      Lua
 * Problem:     D - Largest Group
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/D
 * Status:      AC
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> adj(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        
        adj[u] |= (1 << v);
    }

    int ans = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        int curr = mask;
        
        int curr_ans = adj[__lg(curr)];
        curr ^= 1 << __lg(curr);
        while(curr) {
            curr_ans &= adj[__lg(curr)];
            curr ^= 1 << __lg(curr);
        }

        ans = max(ans, __popcount(curr_ans) + __popcount(mask));
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}

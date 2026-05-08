/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/B
 * Status:      AC
 * Created:     07-05-2026 19:05:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Context {
    int limit;
    const vector<vector<int>>& adj;
    const vector<int>& value;
    vector<pair<int,int>> curr_ans;
};

ll dfs(int u, int p, ll x, Context& ctx) {
    vector<pair<ll, int>> arr;
    for (int v : ctx.adj[u]) if (v != p) arr.emplace_back(dfs(v, u, x, ctx), v);
    sort(arr.begin(), arr.end());
    ll curr = ctx.value[u];
    for (auto [w, v] : arr) {
        if (curr + w <= x) curr += w;
        else ctx.curr_ans.emplace_back(u, v);
    }
    return curr;
}

bool check(ll x, Context& ctx) {
    ctx.curr_ans.clear();
    dfs(0, -1, x, ctx);
    return ctx.curr_ans.size() <= ctx.limit;
}

void solve(Context& ctx) {
    ll l = *max_element(ctx.value.begin(), ctx.value.end());
    ll r = accumulate(ctx.value.begin(), ctx.value.end(), 0LL);
    vector<pair<int,int>> ans;

    while (l <= r) {
        ll m = l + (r-l)/2;

        if (check(m, ctx)) {
            r = m - 1;
            ans = ctx.curr_ans;
        }
        else l = m + 1;
    }

    cout << ans.size() << '\n';
    for (auto [u, v] : ans) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    vector<int> value(n); for (auto &x : value) cin >> x;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Context ctx{k, adj, value};
    solve(ctx);

    return 0;
}

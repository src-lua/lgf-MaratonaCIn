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

vector<vector<int>> adj;
vector<int> value;
int n, limit;
int k;
vector<pair<int,int>> curr_ans;
ll L, R;

ll dfs(int u, int p, ll x) {
    vector<pair<ll, int>> arr;
    for (int v : adj[u]) if (v != p) arr.emplace_back(dfs(v,u, x), v);
    sort(arr.begin(), arr.end());
    ll curr = value[u];
    for (int i = 0; i < arr.size(); i++) {
        if (curr + arr[i].first <= x) curr += arr[i].first;
        else k++, curr_ans.emplace_back(u, arr[i].second);
    }
    return curr;
}

bool check(ll x) {
    k = 0; curr_ans.clear();
    dfs(0, -1, x);
    return k <= limit;
}

void solve() {
    vector<pair<int,int>> ans;

    while (L <= R) {
        ll m = L + (R-L)/2;

        if (check(m)) {
            R = m - 1;
            ans = curr_ans;
        }
        else L = m + 1;
    }

    cout << ans.size() << '\n';
    for (auto [l, r] : ans) {
        cout << l + 1 << ' ' << r + 1   << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> limit;
    value = vector<int>(n); for (auto &x : value) cin >> x;

    L = *max_element(value.begin(), value.end());
    R = accumulate(value.begin(), value.end(), 0LL);
    
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    solve();

    return 0;
}

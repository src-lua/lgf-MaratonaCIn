/**
 * Author:      Lua
 * Problem:     L - The Shortest Path
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/L
 * Status:      AC
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = LLONG_MAX;

void spfa(vector<ll>& dist, vector<vector<pair<int, ll>>>& adj) {
    int n = dist.size();

    queue<int> q;
    vector<bool> inQueue(n, false);
    vector<int> cnt(n, 0);

    for (int i = 0; i < n; i++) {
        q.push(i);
        inQueue[i] = true;
    }

    while (!q.empty()) {
        int u = q.front(); q.pop(); inQueue[u] = false;

        if (dist[u] == -inf) continue;

        for (auto [v, w] : adj[u]) {
            ll d = dist[u] + w;
            if (d < dist[v]) {
                dist[v] = d;
                cnt[v] = cnt[u] + 1;

                if (cnt[v] >= n) dist[v] = -inf;

                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }

    queue<int> negQ;
    for (int u = 0; u < n; u++) if (dist[u] == -inf) negQ.push(u);

    while (!negQ.empty()) {
        int u = negQ.front();
        negQ.pop();
        for (auto [v, w] : adj[u]) {
            if (dist[v] != -inf) {
                dist[v] = -inf;
                negQ.push(v);
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].emplace_back(v, w);
    }

    vector<ll> potential(n, 0);
    spfa(potential, adj);

    for (int i = 0; i < n; i++)
        if (potential[i] == -inf) return cout << "-inf\n", void();

    ll answ = *min_element(potential.begin(), potential.end());
    if (answ == 0) {
        answ = inf;
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : adj[u]) {
                answ = min(answ, w);
            }
        }
    }

    cout << answ << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}

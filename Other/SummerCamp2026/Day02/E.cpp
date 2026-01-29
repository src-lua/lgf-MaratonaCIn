/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://vjudge.net/contest/782309#problem/E
 * Status:      TLE
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

const int MXN = 3e6;

vector<pair<int, int>> dist(MXN, {-1, INT_MAX});

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int bfs(vector<vector<int>>& adj, int n, int start) {
    stack<int> q;

    dist[start] = {start, 0};
    q.push(start);

    while (!q.empty()) {
        auto top = q.top();
        q.pop();

        for (auto e : adj[top]) {
            if (e < n && adj[e].size() > adj[start].size()) continue;
            if (dist[e].first == start) continue;

            dist[e] = {start, dist[top].second + 1};

            if (dist[e].second == 3 && e > n && adj[top].size() <= adj[start].size()) return top;
            if (dist[e].second >= 3) continue;
            q.push(e);
        }
    }

    return -1;
}

int neighbours[MXN];
int visited[MXN];
int cookie = 0;

int solve(const vector<vector<int>>& adj, int start) {
    cookie++;

    for (int u : adj[start]) neighbours[u] = cookie;

    for (int u : adj[start]) {
        for (int v : adj[u]) {
            if (v == start) continue;

            if (visited[v] == cookie) continue;
            visited[v] = cookie;

            if (adj[v].size() > adj[start].size()) continue;

            for (int w : adj[v])
                if (neighbours[w] != cookie) return v;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    auto get_rght = [&](int a) { return n + a + 1; };

    vector<vector<int>> adj(n + m + 10);

    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int x;
            cin >> x;
            x = get_rght(x - 1);
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }

    for (auto& ord : adj) shuffle(begin(ord), end(ord), rng);

    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    shuffle(begin(ord), end(ord), rng);

    for (auto i : ord) {
        // auto ans = bfs(adj, n, i);
        auto ans = solve(adj, i);
        if (ans != -1) {
            cout << "YES\n";
            cout << i + 1 << ' ' << ans + 1 << endl;
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
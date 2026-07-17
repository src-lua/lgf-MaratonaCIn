#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct LCA {
    int N, LOG;
    vector<int> d;
    vector<vector<int>> up;

    LCA(const vector<vector<int>>& adj, int root = 0)
        : N(adj.size()), LOG(__lg(N) + 1), d(N), up(N, vector<int>(LOG + 1, -1)) {

        auto dfs = [&](auto self, int u, int p, int dep) -> void {
            d[u] = dep;
            up[u][0] = (p == -1) ? u : p;
            for (int j = 1; j <= LOG; j++)
                up[u][j] = up[up[u][j - 1]][j - 1];
            for (int v : adj[u]) {
                if (v == p) continue;
                self(self, v, u, dep + 1);
            }
        };

        dfs(dfs, root, -1, 0);
    }

    int parent(int u) {
        return up[u][0] == u ? -1 : up[u][0];
    }

    int kth_ancestor(int u, int k) {
        if (k > d[u]) return -1; 
        for (int j = 0; j <= LOG; j++)
            if ((k >> j) & 1) u = up[u][j];
        return u;
    }

    int lca(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        int diff = d[u] - d[v];
        for (int j = 0; j <= LOG; j++)
            if ((diff >> j) & 1) u = up[u][j];
        if (u == v) return u;
        for (int j = LOG; j >= 0; j--)
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        return up[u][0];
    }

    int dist(int u, int v) {
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }

    bool is_ancestor(int u, int v) {
        return lca(u, v) == u;
    }
};

struct BlockCutTree {
    int N, num_blocks;
    vector<vector<int>> tree;
    vector<vector<int>> blocks;

    BlockCutTree(int n, const vector<vector<int>>& adj) : N(n) {
        int timer = 0;
        vector<int> tin(n, -1), low(n, -1), stack;
        auto dfs = [&](auto self, int u, int p) -> void {
            tin[u] = low[u] = ++timer;
            stack.push_back(u);
            for (int v : adj[u]) {
                if (v == p) continue;
                if (tin[v] != -1) {
                    low[u] = min(low[u], tin[v]);
                } else {
                    self(self, v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] >= tin[u]) {
                        blocks.push_back({});
                        while (true) {
                            int w = stack.back();
                            stack.pop_back();
                            blocks.back().push_back(w);
                            if (w == v) break;
                        }
                        blocks.back().push_back(u);
                    }
                }
            }
        };
        for (int i = 0; i < n; ++i) if (tin[i] == -1) dfs(dfs, i, -1);
        num_blocks = blocks.size();
        tree.resize(N + num_blocks);
        for (int i = 0; i < num_blocks; ++i) {
            for (int u : blocks[i]) {
                tree[u].push_back(N + i);
                tree[N + i].push_back(u);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, q; cin >> n >> m >> q;

    vector<vector<pair<int, ll>>> adj(n);
    vector<vector<int>> unweighted_adj(n);

    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w; u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        unweighted_adj[u].push_back(v);
        unweighted_adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end());

    auto get_w = [&](int u, int v) -> ll {
        int l = 0, r = (int)adj[u].size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (adj[u][mid].first == v) return adj[u][mid].second;
            if (adj[u][mid].first < v) l = mid + 1;
            else r = mid - 1;
        }
        return 0;
    };

    BlockCutTree bct(n, unweighted_adj);
    int num_blocks = bct.num_blocks;

    vector<vector<ll>> pref(num_blocks);
    vector<ll> cycle_tot(num_blocks, 0);

    vector<int> pos_in_parent(n, -1);

    for (int i = 0; i < num_blocks; i++) {
        int sz = bct.blocks[i].size();
        
        if (sz == 2) {
            int u = bct.blocks[i][0];
            int head = bct.blocks[i][1];
            cycle_tot[i] = get_w(u, head);
            pos_in_parent[u] = 0;
        } else {
            pref[i].assign(sz, 0);
            ll tot = 0;
            for (int k = 0; k < sz - 1; k++) {
                int u_node = bct.blocks[i][k];
                int v_node = bct.blocks[i][k+1];
                tot += get_w(u_node, v_node);
                pref[i][k+1] = tot;
                pos_in_parent[u_node] = k;
            }
            int head = bct.blocks[i][sz - 1];
            ll closing_w = get_w(head, bct.blocks[i][0]);
            cycle_tot[i] = tot + closing_w;
        }
    }

    auto get_cycle_dist = [&](int B, int p1, int p2) -> ll {
        if (bct.blocks[B].size() == 2) return cycle_tot[B];
        if (p1 > p2) swap(p1, p2);
        ll dist1 = pref[B][p2] - pref[B][p1];
        ll dist2 = cycle_tot[B] - dist1;
        return min(dist1, dist2);
    };

    vector<ll> D(n, 0);
    auto dfs_dist = [&](auto self, int u, int p, ll curr_d) -> void {
        if (u < n) D[u] = curr_d;

        for (int v : bct.tree[u]) {
            if (v == p) continue;
            if (u < n) {
                self(self, v, u, curr_d);
            } else {
                int B = u - n;
                int pos_head = bct.blocks[B].size() - 1;
                int pos_v = pos_in_parent[v];
                ll dist_in_block = get_cycle_dist(B, pos_head, pos_v);
                self(self, v, u, curr_d + dist_in_block);
            }
        }
    };
    dfs_dist(dfs_dist, 0, -1, 0);

    LCA lca(bct.tree, 0);

    while (q--) {
        int u, v; cin >> u >> v; u--; v--;
        if (u == v) {
            cout << 0 << '\n';
            continue;
        }

        int l = lca.lca(u, v);

        if (l < n) {
            cout << D[u] + D[v] - 2LL * D[l] << '\n';
        } else {
            int B = l - n;
            int X = lca.kth_ancestor(u, lca.d[u] - lca.d[l] - 1);
            int Y = lca.kth_ancestor(v, lca.d[v] - lca.d[l] - 1);

            ll dist_u_to_X = D[u] - D[X];
            ll dist_v_to_Y = D[v] - D[Y];

            int pos_X = pos_in_parent[X];
            int pos_Y = pos_in_parent[Y];
            ll dist_in_cycle = get_cycle_dist(B, pos_X, pos_Y);

            cout << dist_u_to_X + dist_v_to_Y + dist_in_cycle << '\n';
        }
    }

    return 0;
}
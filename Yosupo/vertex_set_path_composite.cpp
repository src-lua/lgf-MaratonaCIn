/**
 * Author:      Lua
 * Problem:     vertex_set_path_composite - Vertex Set Path Composite
 * Link:        https://judge.yosupo.jp/problem/vertex_set_path_composite
 * Status:      ~
 * Created:     29-01-2026 14:32:18
 **/

#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MOD = 998244353;

struct Node {
    ll a, b;

    Node(ll a = 1, ll b = 0) : a(a), b(b) {}

    static Node neutral() { return Node(); }

    static Node merge(const Node& l, const Node& r) {
        return Node(
            (r.a * l.a) % MOD,
            ((r.a*l.b) % MOD + r.b) % MOD
        );
    }
};

template<typename NODE>
struct DoubleNode {
    NODE down;
    NODE up;   

    DoubleNode() : down(NODE()), up(NODE()) {}
    DoubleNode(Node n) : down(n), up(n) {}
    DoubleNode(Node d, Node u) : down(d), up(u) {}

    static DoubleNode neutral() { return DoubleNode(); }

    static DoubleNode merge(const DoubleNode& l, const DoubleNode& r) {
        return {
            Node::merge(l.down, r.down),
            Node::merge(r.up, l.up)       
        };
    }
};

template<typename NODE>
struct SegTree {
    int N;
    vector<NODE> seg;

    SegTree(int n) : N(n) {
        seg.resize(4 * N);
    }

    SegTree(const vector<NODE>& v) : N(v.size()) {
        seg.resize(4 * N);
        build(1, 0, N - 1, v);
    }

    void build(int no, int l, int r, const vector<NODE>& v) {
        if (l == r) {
            seg[no] = v[l];
            return;
        }
        int m = (l + r) >> 1;
        build(no << 1, l, m, v);
        build((no << 1) | 1, m + 1, r, v);
        seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
    }

    void update(int no, int l, int r, int idx, const NODE& val) {
        if (l == r) {
            seg[no] = val;
            return;
        }
        int m = (l + r) >> 1;
        
        if (idx <= m) update(no << 1, l, m, idx, val);
        else update((no << 1) | 1, m + 1, r, idx, val);

        seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
    }

    NODE query(int no, int l, int r, int a, int b) {
        if (b < l || r < a) return NODE::neutral();
        if (a <= l && r <= b) return seg[no];
        int m = (l + r) >> 1;
        return NODE::merge(query(no << 1, l, m, a, b),
                           query((no << 1) | 1, m + 1, r, a, b));
    }

    void update(int idx, NODE val) { update(1, 0, N - 1, idx, val); }
    NODE query(int l, int r) { return query(1, 0, N - 1, l, r); }
};

template<typename NODE>
struct HLD {
    int n, t;
    vector<vector<int>> g;
    vector<int> p, sz, d, h, l_idx;
    SegTree<DoubleNode<NODE>> q; 

    HLD(vector<vector<int>> &adj, const vector<Node>& initial_vals, int root = 0) 
        : n(adj.size()), g(adj), t(0), p(n), sz(n), d(n), h(n), l_idx(n), q(n) {
        
        d[root] = 0, p[root] = root;
        dfs_sz(root); 
        h[root] = root;
        dfs_hld(root);

        vector<DoubleNode<NODE>> ordered_vals(n);
        for(int i = 0; i < n; i++) {
            ordered_vals[l_idx[i]] = DoubleNode<NODE>(initial_vals[i]);
        }
        q = SegTree<DoubleNode<NODE>>(ordered_vals);
    }

    void dfs_sz(int u) {
        sz[u] = 1;
        for (auto &v : g[u]) {
            if (v != p[u]) {
                d[v] = d[u] + 1; 
                p[v] = u;
                dfs_sz(v); 
                sz[u] += sz[v];
                
                if (sz[v] > sz[g[u][0]] || g[u][0] == p[u]) {
                    swap(g[u][0], v);
                }
            }
        }
    }

    void dfs_hld(int u) {
        l_idx[u] = t++;
        for (auto v : g[u]) {
            if (v != p[u]) {
                h[v] = (v == g[u][0] ? h[u] : v);
                dfs_hld(v);
            }
        }
    }

    void update(int u, Node val) {
        q.update(l_idx[u], val);
    }

    NODE query(int u, int v) {
        NODE L = NODE();
        NODE R = NODE();

        while (h[u] != h[v]) {
            if (d[h[u]] > d[h[v]]) { 
                auto res = q.query(l_idx[h[u]], l_idx[u]);
                L = Node::merge(L, res.up);
                u = p[h[u]];
            } 
            else {
                auto res = q.query(l_idx[h[v]], l_idx[v]);
                R = Node::merge(res.down, R);
                v = p[h[v]];
            }
        }

        auto [down, up] = q.query(min(l_idx[u], l_idx[v]), max(l_idx[u], l_idx[v]));        
        if (d[u] < d[v]) R = Node::merge(down, R);
        else L = Node::merge(L, up);              

        return Node::merge(L, R);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<Node> arr(n);
    for (auto &x : arr) cin >> x.a >> x.b;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HLD<Node> hdl(adj, arr);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 0) { // fp ← cx+d
            int pos, c, d; cin >> pos >> c >> d;
            hdl.update(pos, {c, d});
        }

        else if (op == 1) {
            int u, v; cin >> u >> v;
            auto [a,b] = hdl.query(u, v);

            int x; cin >> x;
            cout << ((a * x) % MOD + b) % MOD << '\n';
        }
    }

    return 0;
}

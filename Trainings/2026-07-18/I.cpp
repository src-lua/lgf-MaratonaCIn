/**
 * Author:      Lua
 * Problem:     I
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/701070/problem/I
 * Status:      ~
 * Tags:        
 * Created:     18-07-2026 08:31:07
 **/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

struct LCA {
    int N, LOG;
    vector<int> d;
    vector<vector<int>> up;

    LCA(const vector<vector<int>>& adj, int root = 0)
        : N(adj.size()), LOG(__lg(N) + 1), d(N),
        up(N, vector<int>(LOG +1, -1)) {

        auto dfs = [&](auto self, int u, int p, int dep)-> void {
            d[u] = dep;
            up[u][0] = (p == -1) ? u : p;
            for (int j = 1; j <= LOG; j++)
              up[u][j] = up[up[u][j-1]][j-1];
            for (int v : adj[u]){
                if (v == p) continue;
                self(self, v,u,dep+1);
            }
        };

        dfs(dfs, root, -1, 0);
    }

    int lca(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        int diff = d[u] - d[v];
        for (int j = 0; j <= LOG; j++) if ((diff>>j)&1)u=up[u][j];
        if (u==v) return u;
        for (int j = LOG; j >= 0; j--)
          if (up[u][j] != up[v][j]) {
            u=up[u][j];
            v=up[v][j];
          }
        return up[u][0];
    }
};

struct Tag {
    ll set;

    Tag(int set = -100) : set(set) {}

    void compose(const Tag& t) {
        if (t.set != -100) set = t.set;
    }
};

struct Node {
    ll val;
    Node(ll v = 0) : val(v) {}
    static Node merge(const Node&l, const Node& r) {
        return Node(max(l.val, r.val));
    }
    void apply(const Tag&t, int l, int r) {
        if (t.set != -100) val = t.set;
    }
};

template<typename NODE, typename TAG>
struct LazySegmentTree {
    int N;
    vector<NODE> seg;
    vector<TAG> lazy;

    explicit LazySegmentTree(int n)
        : N(n), seg(4 * n), lazy(4 * n) {}

    template <typename T>
    LazySegmentTree(const vector<T>& v)
        : LazySegmentTree((int)v.size()) {
            build(1,0,N-1,v);
        }

    template <typename T>
    void build(int no, int l, int r, const vector<T>& v) {
        if (l == r) {
            seg[no] = NODE(v[l]);
            return;
        }
        int m = (l + r) >> 1;
        build(no << 1, l, m ,v);
        build((no << 1) | 1, m+1, r, v);
        seg[no] = NODE::merge(seg[no<<1], seg[(no<<1)|1]);
    }

    void push(int no, int lo, int hi) {
        int m = (lo +hi) >> 1;
        int l = no << 1, r = l | 1;

        seg[l].apply(lazy[no], lo, m);
        lazy[l].compose(lazy[no]);
        
        seg[r].apply(lazy[no], m+1, hi);
        lazy[r].compose(lazy[no]);

        lazy[no] = TAG();
    }
    
    void update(int no, int l, int r, int a, int b, const TAG& v) {
        if (b < l || r < a) return;
        if (a<=l && r <= b) {
            seg[no].apply(v,l,r);
            lazy[no].compose(v);
            return;
        }
        push(no, l, r);
        int m = (l + r) >> 1;
        update(no << 1, l, m, a,b,v);
        update((no<<1)|1,m+1,r,a,b,v);
        seg[no] = NODE::merge(seg[no<<1], seg[(no<<1)|1]);
    }

    NODE query(int no, int l, int r, int a, int b) {
        if (b < l || r < a) return NODE();
        if (a<=l && r <= b) return seg[no];
        push(no,l, r);
        int m = (l + r) >> 1;
        return NODE::merge(query(no<<1,l,m,a,b),
                            query((no<<1)|1, m+1,r,a,b));
    }

    void update(int l, int r, const TAG& v) {
        update(1,0,N-1,l,r, v);
    }
    NODE query(int l, int r) { return query(1,0,N-1,l,r);}
};

template<typename NODE, typename TAG>
struct HLD {
    int n, t; 
    vector<int> p, sz, d, head, pos;
    LazySegmentTree<NODE, TAG> st;

    HLD(const vector<vector<int>>& adj, const vector<NODE>& vals, int root = 0)
        : n(adj.size()), t(0), p(n), sz(n), d(n), head(n), pos(n), st(n) {
            vector<vector<int>> g = adj;
            d[root] = 0, p[root] = root;

            auto dfs_sz = [&](auto self, int u) -> void {
                sz[u] = 1;
                int best_v = -1, max_sz = -1;
                for (auto &v : g[u]) {
                    if (v == p[u]) continue;
                    d[v] = d[u] + 1;
                    p[v] = u;
                    self(self, v);
                    sz[u] += sz[v];
                    if (sz[v] > max_sz) {
                        max_sz = sz[v];
                        best_v = v;
                    }
                }
            if (best_v != -1) {
                for(int i =0; i <g[u].size(); i++) {
                    if (g[u][i] == best_v && i != 0) {
                        swap(g[u][0], g[u][i]);
                        break;
                    }
                }
            }
        };

        auto dfs_hld = [&](auto self, int u) -> void {
            pos[u] = t++;
            for (int i = 0; i < (int)g[u].size(); i++) {
                int v = g[u][i];
                if (v == p[u]) continue;
                head[v] = (i == 0 ? head[u] : v);
                self(self, v);
            }
        };

        dfs_sz(dfs_sz, root);
        head[root] = root;
        dfs_hld(dfs_hld, root);

        vector<NODE> base(n);
        for (int i = 0; i < n; i++) base[pos[i]] = vals[i];
        st = LazySegmentTree<Node,Tag>(base);
    }

    void update_path(int u, int v, const TAG& tag) {
        while (head[u] != head[v]) {
            if (d[head[u]] > d[head[v]]) swap(u, v);
            st.update(pos[head[v]], pos[v], tag);
            v = p[head[v]];
        }
        if (d[u] > d[v]) swap(u, v);
        st.update(pos[u], pos[v], tag);
    }

    void query_path(int u, int v) {
        NODE res;
        while (head[u] != head[v]) {
            if (d[head[u]] > d[head[v]]) swap(u, v);
            res = NODE::merge(res, st.query(pos[head[v]], pos[v]));
            v = p[head[v]];
        }
        if (d[u] > d[v]) swap(u, v);
        return NODE::merge(res, st.query(pos[u], pos[v]));
    }
};

void dfs(int v, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &order){
    vis[v] = true;
    for(auto u : adj[v]){
        if(!vis[u]){
            dfs(u, adj, vis, order);
        }
    }
    order.push_back(v);
 
    return;
}
 
void kosaraju(vector<vector<int>> &adj, vector<int> &c, vector<vector<int>> &comps, vector<vector<int>> &dag){
    int n = adj.size();
    vector<int> order;
    vector<bool> vis(n, false);
 
    for(int i = 1; i < n; i++){
        if(!vis[i]){
            dfs(i, adj, vis, order);
        }
    }
 
    vector<vector<int>> adj_transp(n);
 
    for(int v = 1; v < n; v++){
        for(auto u : adj[v]){
            adj_transp[u].push_back(v);
        }
    }
 
    vis = vector<bool>(n, false);
    reverse(order.begin(), order.end());
 
    for(auto v : order){
        if(!vis[v]){
            vector<int> comp;
            dfs(v, adj_transp, vis, comp);
            comps.push_back(comp);
        }
    }
    vector<bool> mark(comps.size());
    for(int i = 0; i < comps.size(); i++){
        for(auto v : comps[i])c[v] = i;
    }
 
    for(int i = 1; i < n; i++){
        for(auto v : adj[i]){
            if(!((c[i]==c[v]) || (mark[c[v]]))){
                mark[c[v]] = true;
                dag[c[i]].push_back(c[v]);
            }
        }
        for(auto v : adj[i]) mark[c[v]] = false;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; cin >> n;
    int bombanuclear;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> bombanuclear;
        adj[i].push_back(bombanuclear);
        //if(f[i] == i) f[i] = -1;
    }
    vector<int>c(n+1);
    vector<vector<int>> comps, dag(n+1);
    kosaraju(adj, c, comps, dag);
 
    int x = 0;
 
}
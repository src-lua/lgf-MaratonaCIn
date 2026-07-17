/**
 * Author:      Lua
 * Problem:     C
 * Link:        https://codeforces.com/gym/106495/problem/C
 * Status:      ~
 * Created:     10-07-2026 08:10:03
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, ll>;

struct BlockCutTree {
    vector<vector<int>> g, tree, comp;
    vector<int> id, cut;
    BlockCutTree(int n) : n(n), g(n), cut(n) {}

    void addEdge(int u, int v){
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    void build(){ 
        pre = low = id = vector<int>(n, -1);
        for(int u=0; u<n; u++, chd=0) if(pre[u] == -1) //if graph is disconected
            tarjan(u, -1), makeComp(-1);               //find cut vertex and make components
        
        for(int u=0; u<n; u++) if(cut[u]) comp.emplace_back(1, u); //create cut components
        for(int i=0; i<comp.size(); i++)                           //mark id of each node
            for(auto u : comp[i]) id[u] = i;
        
        tree.resize(comp.size());
        for(int i=0; i<comp.size(); i++)
            for(auto u : comp[i]) if(id[u] != i) 
                tree[i].push_back(id[u]),
                tree[id[u]].push_back(i);
    }
private:
    vector<int> pre, low;
    vector<pair<int, int>> st;
    int n, clk = 0, chd=0, ct, a, b;
    
    void makeComp(int u){
        comp.emplace_back();
        do {
            tie(a, b) = st.back(); 
            st.pop_back();
            comp.back().push_back(b);
        } while(a != u);
        if(~u) comp.back().push_back(u);
    }

    void tarjan(int u, int p){
        pre[u] = low[u] = clk++;
        st.emplace_back(p, u);

        for(auto v : g[u]) if(v != p){
            if(pre[v] == -1){
                tarjan(v, u);
                low[u]  =  min(low[u], low[v]);
                cut[u] |= ct = (~p && low[v] >= pre[u]) || (p==-1 && ++chd >= 2);
                if(ct) makeComp(u);
            }
            else low[u] = min(low[u], pre[v]);
        }
    }
};

template<typename NODE>
struct SparseTable {
    int N, K;
    vector<vector<NODE>> st;
    vector<int> lg;

    template<typename T>
    SparseTable(const vector<T>& v) : N(v.size()) {
        K = (N > 0) ? __lg(N) : 0;
        st.assign(K + 1, vector<NODE>(N));
        lg.assign(N + 1, 0);
        for (int i = 2; i <= N; i++) lg[i] = lg[i / 2] + 1;
        for (int i = 0; i < N; i++) st[0][i] = NODE(v[i]);
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[j][i] = NODE::merge(st[j - 1][i],
                                       st[j - 1][i + (1 << (j - 1))]);
    }

    NODE query(int l, int r) {
        int j = lg[r - l + 1];
        return NODE::merge(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

struct LCANode {
    int dep, id;
    LCANode(int d = 1e9, int pos = -1) : dep(d), id(pos) {}
    
    static inline LCANode merge(const LCANode& l, const LCANode& r) {
        return l.dep < r.dep ? l : r;
    }
};

struct LCA {
    int N;
    vector<int> first, tour, d, p;
    SparseTable<LCANode> st;

    LCA(int n, int root, const vector<vector<int>>& adj) 
        : N(n), first(n), d(n), p(n, -1), st(vector<LCANode>()) {
        
        vector<int> tour_depths;
        tour.reserve(2 * n);
        tour_depths.reserve(2 * n);

        auto dfs = [&](auto self, int u, int parent_id, int dep) -> void {
            p[u] = parent_id;
            d[u] = dep;
            first[u] = tour.size();
            tour.push_back(u);
            tour_depths.push_back(dep);
            for (int v : adj[u]) {
                if (v == parent_id) continue;
                self(self, v, u, dep + 1);
                tour.push_back(u);
                tour_depths.push_back(dep);
            }
        };

        dfs(dfs, root, -1, 0);
        vector<LCANode> st_init(tour.size());
        for (int i = 0; i < (int)tour.size(); i++) {
            st_init[i] = LCANode(tour_depths[i], i);
        }
        st = SparseTable<LCANode>(st_init);
    }

    int parent(int u) {
        return p[u];
    }

    int lca(int u, int v) {
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);
        return tour[st.query(l, r).id];
    }

    int dist(int u, int v) {
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }

    bool is_ancestor(int u, int v) {
        return lca(u, v) == u;
    }
};

ll dfs (int u, int p, int t, vector<vector<pii>>& adj) {
    if (u == t) return 0;
    
    ll an = LLONG_MAX;

    for (auto &[v, w] : adj[u]) if (v != p) {
        an = min(an, w + dfs(v, u, t, adj));
    }

    return an;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m , q; cin >> n >> m >> q;
    vector<vector<pii>> adj(n); 

    BlockCutTree bcc(n);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);

        bcc.addEdge(u, v);
    }

    vector<vector<int>> components(n);
    map<pair<int,int>,int> pontes;
    bcc.build();
    for (int i = 0; i < n; i++) {
        for (auto &x : bcc.comp[i])
        components[x].push_back(i);
        
        if (bcc.comp[i].size() == 2) {
            int a = bcc.comp[i][0], b = bcc.comp[i][1];
            if (a > b) swap(a, b);
            pontes[{a,b}] = i;
        }
    }
    vector<vector<int>> revcomp(n);
    for(int i = 0; i < bcc.comp.size(); i++){
        for(auto &etc2 : bcc.comp[i]){
            revcomp[etc2].push_back(i);
        }
    }
    LCA lca(2*n + 10, 0, bcc.tree);
    
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v; u--, v--;
        int l = lca.lca(revcomp[u][0], revcomp[v][0]);

        int f = u;

        vector<int> path_, path;
        
        while(f != l)
        for (auto e : bcc.tree[f]) if (!lca.is_ancestor(f, e)) path.push_back(f), f = e;

        f = v;
        while(f != l)
        for (auto e : bcc.tree[f]) if (!lca.is_ancestor(f, e)) path_.push_back(f), f = e;

        path.reserve(path.size()+1+path_.size());
        path.push_back(l);

        reverse(path_.begin(), path_.end());
        for (auto &x : path_) path.emplace_back(x);

        ll ans = 0;

        int sair = u;
        int a_ = path[0], b_ = path[1]; if (a_ > b_) swap(a_, b_); 
        int chegar = pontes[{a_, b_}];

        auto get = [&](int u, int v) {
            ll answ = LLONG_MAX;

            int a = bcc.comp[u][0], b = bcc.comp[u][1];
            int c = bcc.comp[v][0], d = bcc.comp[v][1];

            int comp;
            if (a == c || a == d) comp = a;
            if (b == c || b == d) comp = b;

            pii r = {-1, -1}, l = {-1, -1};
            for (auto &[x, w] : adj[u]) {
                if (find(bcc.comp[x].begin(), bcc.comp[x].end(), comp) != bcc.comp[x].end()) {
                    if (r == pii{-1, -1}) r = {x, w};
                    else l = {x, w};
                }
            }

            vector<bool> visited(n, false);
            visited[u] = true;

            if (r != pii{-1, -1}) {
                answ = min(answ, r.second+dfs(r.first, u, v, adj));
            }

            if (l != pii{-1, -1}) {
                answ = min(answ, l.second+dfs(l.first, u, v, adj));
            }

            return answ;
        };

        ans += get(sair, chegar);

        for (int i = 1; i < (int)path.size() - 1; i++) {
            int a = path[i], b = path[i+1]; if (a > b) swap(a, b);

            sair = chegar;
            chegar = pontes[{a,b}];

            ans += get(sair, chegar);
        }

        sair = chegar;
        chegar = v;

        ans += get(sair, chegar);
    
        cout << ans << '\n';
    }
    
    return 0;
}
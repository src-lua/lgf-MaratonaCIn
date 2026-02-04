#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using vi = vector<int>;
using Graph = vector<vi>;

template<typename X>
struct PST {
    struct ind {
        X dt;
        int l, r;
        ind() : dt(X()), l(0), r(0) {}
    };

    int N;
    vector<ind> st;
    vi rt;

    PST(int n) : N(n) {
        st.reserve(1e8); st.emplace_back();
        rt.push_back(0);
    }

    int upd(int p_root, int L, int R, int i, X v) {
        int nd = st.size();
        if (p_root == 0) st.emplace_back();
        else st.push_back({st[p_root]});

        if (L == R) {
            st[nd].dt = X::mg(st[nd].dt, v);
            return nd;
        }

        int mid = L + (R - L) / 2;

        if (i <= mid) {
            int p_left = (p_root == 0) ? 0 : st[p_root].l;
            st[nd].l = upd(p_left, L, mid, i, v);
        } 

        else {
            int p_right = (p_root == 0) ? 0 : st[p_root].r;
            st[nd].r = upd(p_right, mid + 1, R, i, v);
        }

        st[nd].dt = X::mg(st[st[nd].l].dt, st[st[nd].r].dt);
        return nd;
    }

    X qr(int nd, int L, int R, int i, int j) {
        if (nd == 0 || i > R || j < L) return X();
        if (i <= L && R <= j) return st[nd].dt;
        int mid = L + (R - L) / 2;
        return X::mg(qr(st[nd].l, L, mid, i, j),
                           qr(st[nd].r, mid + 1, R, i, j));
    }

    int walk(int _l, int _r, int _lca, int _pr, int L, int R, int k) {
        if (L == R) return L;
        
        int mid = L + (R - L) / 2;

        int l_i_l = st[_l].l;
        int l_i_r = st[_r].l;
        int l_i_lca = st[_lca].l;
        int l_i_pr = st[_pr].l;
        
        int c_l = (l_i_l == 0) ? 0 : st[l_i_l].dt.cnt;
        int c_r = (l_i_r == 0) ? 0 : st[l_i_r].dt.cnt;
        int c_lca = (l_i_lca == 0) ? 0 : st[l_i_lca].dt.cnt;
        int c_pr = (l_i_pr == 0) ? 0 : st[l_i_pr].dt.cnt;

        int cnt_left = c_r + c_l - c_lca - c_pr;

        if (cnt_left >= k)
            return walk(st[_l].l, st[_r].l, st[_lca].l, st[_pr].l, L, mid, k);
        else
            return walk(st[_l].r, st[_r].r, st[_lca].r, st[_pr].r, mid + 1, R, k - cnt_left);
    }

    int walk(int l, int r, int lca, int pr, int k) {
        return walk(rt[l], rt[r], rt[lca], (pr == -1) ? 0 : rt[pr], 0, N - 1, k);
    }

    void upd(int i, X v) {
        rt.push_back(upd(rt.back(), 0, N - 1, i, v));
    }

    X qr(int version, int l, int r) {
        return qr(rt[version], 0, N - 1, l, r);
    }
};

template<typename X>
struct SpT {
    int N, K;
    vector<vector<X>> st;
    vi lg;

    template<typename T>
    SpT(const vector<T>& v) : N(v.size()) {
        K = (N > 0) ? __lg(N) : 0;
        st.assign(K + 1, vector<X>(N));
        lg.assign(N + 1, 0);
        for (int i = 2; i <= N; i++) lg[i] = lg[i / 2] + 1;
        for (int i = 0; i < N; i++) st[0][i] = X(v[i], i);
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[j][i] = X::mg(st[j - 1][i],
                                       st[j - 1][i + (1 << (j - 1))]);
    }

    X qr(int l, int r) {
        int j = lg[r - l + 1];
        return X::mg(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

struct lnd {
    int dep, id;
    lnd(int d = 1e9, int pos = -1) : dep(d), id(pos) {}
    lnd(const lnd& other, int pos) : dep(other.dep), id(pos) {}
    
    static inline lnd mg(const lnd& l, const lnd& r) {
        return l.dep < r.dep ? l : r;
    }
};

struct LCA {
    int N;
    vi f, t, d, p;
    SpT<lnd> st;

    LCA(int n, int root, const vector<vi>& aj) 
        : N(n), f(n), d(n), p(n, -1), st(vector<lnd>()) {
        
        vector<lnd> nds;
        t.reserve(2 * n);
        nds.reserve(2 * n);

        auto dfs = [&](auto self, int u, int pr_id, int dep) -> void {
            p[u] = pr_id;
            d[u] = dep;
            f[u] = t.size();
            t.push_back(u);
            nds.emplace_back(dep, (int)t.size() - 1);
            for (int v : aj[u]) {
                if (v == pr_id) continue;
                self(self, v, u, dep + 1);
                t.push_back(u);
                nds.emplace_back(dep, (int)t.size() - 1);
            }
        };

        dfs(dfs, root, -1, 0);
        st = SpT<lnd>(nds);
    }

    int lca(int u, int v) {
        int l = f[u], r = f[v];
        if (l > r) swap(l, r);
        return t[st.qr(l, r).id];
    }
};

const int root = 0;

struct nd {
    int cnt;
    nd(int v = 0) : cnt(v) {}
    
    static nd ntr() { return nd(0); }
    
    static nd mg(const nd& l, const nd& r) { return nd(l.cnt + r.cnt); }
};

using Seg = PST<nd>;

void dfs(Seg& seg, Graph& aj, vi& a, int u, int p = -1) {
    if (p != -1) seg.rt[u] = (seg.upd(seg.rt[p], 0, seg.N - 1, a[u], nd(1)));
    
    for (auto v : aj[u]) {
        if (v == p) continue;
        
        dfs(seg, aj, a, v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vi a(n);
    for (auto& x : a) cin >> x;

    vi V = a;
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    auto get_id = [&](int val) {
        return lower_bound(V.begin(), V.end(), val) - V.begin();
    };
    
    for (auto& x : a) x = get_id(x);

    Graph aj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;

        aj[u].push_back(v);
        aj[v].push_back(u);
    }

    PST<nd> seg(V.size());
    LCA lca(n, root, aj);

    seg.rt.resize(n);
    seg.rt[root] = seg.upd(0, 0, seg.N-1, a[root], nd(1));
    dfs(seg, aj, a, root);
    
    for (int i = 0; i < q; i++) {
        int u, v, k; cin >> u >> v >> k; u--, v--;

        cout << V[seg.walk(u, v, lca.lca(u, v), lca.p[lca.lca(u, v)], k)] << '\n';
    }

    return 0;
}
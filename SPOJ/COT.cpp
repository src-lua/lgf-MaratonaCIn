/**
 * Author:      Lua
 * Problem:     COT - Count on a tree
 * Link:        https://www.spoj.com/problems/COT/
 * Status:      AC
 * Created:     03-02-2026 21:49:30
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using Graph = vector<vector<int>>;

#include "lgf-cplib/data-structures/segment-tree/dynamic-persistent-segment-tree.hpp"

template<typename NODE>
struct walkPST : public PersistentSegmentTree<NODE> {
    using PersistentSegmentTree<NODE>::PersistentSegmentTree;
    using PersistentSegmentTree<NODE>::st;
    using PersistentSegmentTree<NODE>::roots;
    using PersistentSegmentTree<NODE>::N;

    int walk(int node_l, int node_r, int node_lca, int node_parent, int L, int R, int k) {
        if (L == R) return L;
        
        int mid = L + (R - L) / 2;

        int left_idx_l = st[node_l].l;
        int left_idx_r = st[node_r].l;
        int left_idx_lca = st[node_lca].l;
        int left_idx_parent = st[node_parent].l;
        
        int cnt_l = (left_idx_l == 0) ? 0 : st[left_idx_l].data.count;
        int cnt_r = (left_idx_r == 0) ? 0 : st[left_idx_r].data.count;
        int cnt_lca = (left_idx_lca == 0) ? 0 : st[left_idx_lca].data.count;
        int cnt_parent = (left_idx_parent == 0) ? 0 : st[left_idx_parent].data.count;

        int count_left = cnt_r + cnt_l - cnt_lca - cnt_parent;

        if (count_left >= k)
            return walk(st[node_l].l, st[node_r].l, st[node_lca].l, st[node_parent].l, L, mid, k);
        else
            return walk(st[node_l].r, st[node_r].r, st[node_lca].r, st[node_parent].r, mid + 1, R, k - count_left);
    }

    int walk(int l, int r, int lca, int parent, int k) {
        return walk(roots[l], roots[r], roots[lca], (parent == -1) ? 0 : roots[parent], 0, N - 1, k);
    }
};

#include "lgf-cplib/graphs/lca.hpp"

struct Node {
    int count;
    Node(int v = 0) : count(v) {}
    
    static Node neutral() { return Node(0); }
    
    static Node merge(const Node& l, const Node& r) { return Node(l.count + r.count); }

    inline void apply(Node& node) {
        count += node.count;
    }
};

using Seg = walkPST<Node>;

void dfs(Seg& seg, Graph& adj, vector<int>& arr, int u, int p = -1) {
    if (p != -1) seg.roots[u] = (seg.update(seg.roots[p], 0, seg.N - 1, arr[u], Node(1)));
    
    for (auto v : adj[u]) {
        if (v == p) continue;
        
        dfs(seg, adj, arr, v, u);
    }
}

ll clamp(ll x, ll l, ll r) {
    return max(l, min(x, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    auto compress = arr;
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());

    auto get_id = [&](int val) {
        return lower_bound(compress.begin(), compress.end(), val) - compress.begin();
    };

    for (auto &x : arr) x = get_id(x);

    Graph adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int root = 0;

    Seg seg(compress.size());
    LCA lca(n, root, adj);

    seg.roots.resize(n);
    seg.roots[root] = seg.update(0, 0, seg.N-1, arr[root], Node(1));
    dfs(seg, adj, arr, root);
    
    for (int i = 0; i < q; i++) {
        int u, v, k; cin >> u >> v >> k; u--, v--;

        cout << compress[seg.walk(u, v, lca.lca(u, v), lca.parent(lca.lca(u, v)), k)] << '\n';
    }

    return 0;
}
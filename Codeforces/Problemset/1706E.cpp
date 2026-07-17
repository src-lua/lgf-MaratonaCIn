/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://codeforces.com/problemset/problem/1706/E
 * Status:      ~
 * Created:     17-07-2026 12:58:47
 **/

#include <bits/stdc++.h>

#include "lib/data-structures/parallel-bs.hpp"
#include "lib/data-structures/dsu-rollback.hpp"
#include "lib/data-structures/sparse-table/sparse-table.hpp"

using namespace std;
using pii = pair<int,int>;

struct Node {
    int val, pos;
    Node(int v = -2e9, int p = -1) : val(v), pos(p) {}

    static Node merge(const Node& l, const Node& r) {
        return l.val <= r.val ? r : l;
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<pii> edges;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        edges.emplace_back(u, v);
    }

    vector<pii> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        queries[i] = {l, r};
    }

    DSURollback dsu(n);

    auto apl = [&](int i) {
        auto [u, v] = edges[i];
        dsu.join(u, v);
    };

    auto rlb = [&](int i) {
        dsu.rollback();
    };

    auto chk = [&](int i) {
        return dsu.find(i) == dsu.find(i+1);
    };

    ParallelBS pbs(n-1, m);
    pbs.run(apl, rlb, chk);

    SparseTable<Node> st(pbs.ans);

    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        auto [l, r] = queries[i];
        ans[i] = (l == r ? 0 : st.query(l, r-1).val + 1);
    }
    
    for (auto &x : ans) cout << x << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();    

    return 0;
}

/**
 * Author:      Lua
 * Problem:     1737 - Range Queries and Copies
 * Link:        https://cses.fi/problemset/task/1737
 * Status:      AC
 * Created:     04-02-2026 10:37:19
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

#include "lgf-cplib/data-structures/segment-tree/dynamic-persistent-segment-tree.hpp"

struct Node {
    ll val;
    Node(ll v = 0) : val(v) {}
    static inline Node merge(const Node& l, const Node& r) {
        return Node(l.val + r.val);
    }

    inline void apply(Node& x) {
        val = x.val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<int> arr(n); for (auto &x : arr) cin >> x;

    PersistentSegmentTree<Node> seg(n);
    int root = 0;
    for (int i = 0; i < n; i++)
        root = seg.update(root, 0, n - 1, i, arr[i]);
    seg.roots.push_back(root);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 1) {
            int k, i, x; cin >> k >> i >> x; i--;

            seg.roots[k] = seg.update(seg.roots[k], 0, n - 1, i, {x});
        }

        else if (op == 2) {
            int k, l, r; cin >> k >> l >> r; l--, r--;

            cout << seg.query(k, l, r).val << '\n';
        }

        else if (op == 3) {
            int k; cin >> k;

            seg.roots.push_back(seg.roots[k]);
        }
    }

    return 0;
}

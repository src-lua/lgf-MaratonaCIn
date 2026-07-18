/**
 * Author:      Lua
 * Problem:     1736 - Polynomial Queries
 * Link:        https://cses.fi/problemset/task/1736
 * Status:      AC
 * Created:     04-02-2026 01:40:23
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include "lib/data-structures/segment-tree/lazy-segment-tree.hpp"

struct Tag {
    ll a, b;

    Tag(ll a = 0, ll b = 0) : a(a), b(b) {};

    void inline compose(const Tag& t) {
        a += t.a, b += t.b;
    }
};

struct Node {
    ll val = 0;
    Node(ll v = 0) : val(v) {}
    static inline Node merge(const Node& l, const Node& r) {
        return Node(l.val + r.val);
    }

    // val(i) = i−a+1 onde a é o inicio da pa
    void inline apply(const Tag& t, int l, int r) {
        ll len = r - l + 1;
        ll sum_indices = (ll)(l + r) * len / 2;

        val += t.a * sum_indices + t.b * len;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<int> arr(n); for (auto &x : arr) cin >> x;

    LazySegmentTree<Node, Tag> seg(arr);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 1) {
            int l, r; cin >> l >> r; l--, r--;
            
            seg.update(l, r, {1, -l+1});
        }

        else if (op == 2) {
            int l, r; cin >> l >> r; l--, r--;

            cout << seg.query(l, r).val << '\n';
        }
    }

    return 0;
}

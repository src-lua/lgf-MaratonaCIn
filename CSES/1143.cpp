/**
 * Author:      Lua
 * Problem:     1143 - Hotel Queries
 * Link:        https://cses.fi/problemset/task/1143
 * Status:      AC
 * Created:     06-02-2026 01:29:15
 **/

#include <bits/stdc++.h>

#include "lib/data-structures/segment-tree/segment-tree.hpp"

struct Node {
    int val;

    Node(int val = 0) : val(val) {}

    static inline Node merge(const Node& l, const Node& r) {
        Node res;
        res.val = max(l.val, r.val);
        return res;
    }

    inline void apply(const Node& v) { val += v.val; }
};

int walk(SegTree<Node>& seg, int target, int no = 1, int l = 0, int r = -1) {
    if (r == -1) r = seg.N - 1;
    if (seg.seg[no].val < target) return -1;

    if (l == r) return l;

    int m = (l + r) >> 1;
    int e = no << 1, d = e | 1;

    if (seg.seg[e].val >= target)
        return walk(seg, target, e, l, m);
    else
        return walk(seg, target, d, m + 1, r);
}

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    SegTree<Node> seg(arr);

    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        int hotel = walk(seg, x);
        cout << hotel + 1 << ' ';

        if (hotel != -1) seg.update(hotel, {-x});
    }

    return 0;
}

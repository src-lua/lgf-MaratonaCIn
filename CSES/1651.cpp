/**
 * Author:      Lua
 * Problem:     1651 - Range Update Queries
 * Link:        https://cses.fi/problemset/task/1651
 * Status:      AC
 * Created:     04-02-2026 01:33:34
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include "lib/data-structures/segment-tree/dual-segment-tree.hpp"

struct Tag {
    ll add = 0;
    void compose(const Tag& t) {
        add += t.add;
    }
    void apply(ll& val) { val += add; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<ll> arr(n); for (auto &x : arr) cin >> x;

    DualSegTree<ll, Tag> seg(arr);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 1) {
            int l, r, x; cin >> l >> r >> x; l--, r--;

            seg.update(l, r, {x});
        }

        else if (op == 2) {
            int idx; cin >> idx; idx--;

            cout << seg.get(idx) << '\n';
        }
    }
    

    return 0;
}

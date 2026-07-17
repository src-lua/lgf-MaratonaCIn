/**
 * Author:      Lua
 * Problem:     METEORS
 * Link:        https://www.spoj.com/problems/METEORS/
 * Status:      ~
 * Created:     17-07-2026 08:58:22
 **/

#include <bits/stdc++.h>
#include "lib/data-structures/segment-tree/lazy-segment-tree.hpp"
#include "lib/data-structures/parallel-bs.hpp"

using namespace std;
using ll = long long;
using iii = tuple<int,int,int>;

struct Tag {
    ll add = 0;
    void compose(const Tag& t) { add += t.add; }
};

struct Node {
    ll val = 0;
    Node(ll v = 0) : val(v) {}
    static Node merge(const Node& l, const Node& r) { return Node(l.val + r.val); }
    void apply(const Tag& t, int l, int r) { val += t.add * (r - l + 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> owner(m); for (auto &x : owner) cin >> x;
    vector<int> intent(n); for (auto &x : intent) cin >> x;

    vector<vector<int>> sectors(n);
    for (int i = 0; i < m; i++) sectors[owner[i]-1].push_back(i);

    int q; cin >> q; vector<iii> rains(q);
    for (int i = 0; i < q; i++) {
        int l, r, x; cin >> l >> r >> x; l--, r--;
        rains[i] = {l, r, x};
    }

    LazySegmentTree<Node, Tag> seg(m);

    auto upd = [&](int i) {
        auto [l, r, x] = rains[i];
        if (l <= r) seg.update(l, r, {x});
        else { seg.update(l, m-1, {x}); seg.update(0, r, {x}); }
    };

    auto rlb = [&](int i) {
        auto [l, r, x] = rains[i];
        if (l <= r) seg.update(l, r, {-x});
        else { seg.update(l, m-1, {-x}); seg.update(0, r, {-x}); }
    };

    auto tst = [&](int idx) {
        ll val = 0;
        for (int s : sectors[idx]) {
            val += seg.query(s, s).val;
            if (val >= intent[idx]) return true;
        }
        return false;
    };

    ParallelBS pbs(n, q);
    pbs.run(upd, rlb, tst);

    for (auto x : pbs.ans)
        cout << (x != -1 ? to_string(x+1) : "NIE") << '\n';

    return 0;
}

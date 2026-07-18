/**
 * Author:      Lua
 * Problem:     E - Physical Education Lessons
 * Link:        https://codeforces.com/problemset/problem/915/E
 * Status:      AC
 * Created:     04-02-2026 02:24:14
 **/

#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int,int,int>;

using ll = long long int;

#include "lib/data-structures/segment-tree/dynamic-segment-tree.hpp"

struct Tag {
    int set = -1;

    Tag(int set = -1) : set(set) {}

    bool operator==(const Tag& t) const {
        return set == t.set;
    }

    void compose(const Tag& t) {
        if (t.set != -1) set = t.set;
    }
};

struct Node {
    int val = 0;
    static Node merge(const Node& l, const Node& r) {
        return {l.val + r.val};
    }
    void apply(const Tag& t, ll l, ll r) {
        if (t.set != -1) val = t.set * (r-l+1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;

    DynamicSegTree<Node, Tag> seg(0, n);
    seg.seg.reserve(123e5);

    seg.update(0, n-1, {1});

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        int op; cin >> op;

        seg.update(l, r, {op-1});
        cout << seg.query(0, n).val << '\n';
    }

    return 0;
}

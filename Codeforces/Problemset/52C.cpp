/**
 * Author:      Lua
 * Problem:     C - Circular RMQ
 * Link:        https://codeforces.com/problemset/problem/52/C
 * Status:      AC
 * Created:     04-02-2026 02:00:21
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include "lib/data-structures/segment-tree/lazy-segment-tree.hpp"

struct Tag {
    ll val;
    Tag(int v = 0) : val(v) {}

    void inline compose(const Tag& t) {
        val += t.val;
    }
};

struct Node {
    ll val;
    Node(ll v = 1e18) : val(v) {}

    static inline Node merge(const Node& l, const Node& r) {
        return Node(min(l.val, r.val));
    }

    void inline apply(const Tag& t, int l, int r) {
        if (val != 1e18) val += t.val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n); for (auto &x : arr) cin >> x;

    LazySegmentTree<Node, Tag> seg(arr);



    int q; cin >> q; cin.ignore();
    for (int i = 0; i < q; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);int l, r, v;
        
        ss >> l >> r; 
        if (ss >> v) {
            if (l <= r) seg.update(l, r, {v});
            else seg.update(l, n-1, {v}), seg.update(0, r, {v});
        }
        
        else {
            if (l <= r) cout << seg.query(l, r).val << '\n';    
            else 
                cout << min(seg.query(l, n-1).val, seg.query(0, r).val) << '\n';
        }
    }


    return 0;
}

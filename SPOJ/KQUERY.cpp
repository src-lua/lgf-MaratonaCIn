/**
 * Author:      Lua
 * Problem:     KQUERY
 * Link:        https://www.spoj.com/problems/KQUERY/
 * Status:      AC
 * Created:     04-02-2026 01:04:29
 **/

#include <bits/stdc++.h>

using namespace std;

#include "lib/data-structures/segment-tree/dynamic-persistent-segment-tree.hpp"

struct Node {
    int val;
    Node(int v = 0) : val(v) {}

    inline static Node neutral() { return Node(0); }

    inline static Node merge(const Node& l, const Node& r) { 
        return Node(l.val + r.val);
    }

    inline void apply(Node& node) { val += node.val; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    vector<pair<int,int>> v;

    for (int i = 0; i < n; i++) v.emplace_back(arr[i], i);
    sort(v.rbegin(), v.rend());

    PersistentSegmentTree<Node> seg(n);
    for (auto const &[x, i] : v) seg.update(i, {1});

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k; l--, r--;

        int version = distance(upper_bound(v.rbegin(), v.rend(), make_pair(k, n)), v.rend());

        cout << seg.query(version, l, r).val << '\n';
    }

    return 0;
}

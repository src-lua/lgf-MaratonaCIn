/**
 * Author:      Lua
 * Problem:     DQUERY - D-query
 * Link:        https://www.spoj.com/problems/DQUERY/
 * Status:      AC
 * Created:     04-02-2026 00:32:16
 **/

#include <bits/stdc++.h>

#include "lgf-cplib/data-structures/segment-tree/dynamic-persistent-segment-tree.hpp"

struct Node {
    int val;
    Node(int v = 0) : val(v) {}

    inline static Node neutral() { return Node(0); }

    inline static Node merge(const Node& l, const Node& r) { 
        return Node(l.val + r.val);
    }

    inline void apply(Node& node) { val = node.val; }
};

using namespace std;

const int MXN = 1e6+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n); for(auto &x : arr) cin >> x;

    vector<int> last(MXN, -1);

    PersistentSegmentTree<Node> seg(n);
    for (int i = 0; i < n; i++) {
        int rt = seg.roots.back(); 
        if (last[arr[i]] != -1)
            rt = seg.update(rt, 0, n - 1, last[arr[i]], Node(0));
        
        seg.roots.push_back(seg.update(rt, 0, n - 1, i, Node(1)));
        
        last[arr[i]] = i;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;

        cout << seg.query(r+1, l, r).val << '\n'; 
    }

    return 0;
}

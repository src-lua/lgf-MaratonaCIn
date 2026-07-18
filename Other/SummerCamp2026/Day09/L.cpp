/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://vjudge.net/contest/783195#problem/L
 * Status:      AC
 * Created:     30-01-2026 20:41:29
 **/

#include <bits/stdc++.h>

using namespace std;

// #include "lib/data-structures/segment-tree/lazy-segment-tree.hpp"
#include "lib/data-structures/segment-tree/dual-segment-tree.hpp"

struct Tag {
    int set;
    
    Tag(int x = -1) :set(x) {}
    
    void compose(const Tag& t) {
        if (t.set != -1) set = t.set;
    }

    void apply(int& val) {
        if (set != -1) val = set;
    }
};

struct Node {
    int val = 0;

    Node(int v = 0) : val(v) {}

    static Node neutral() { return Node(0); }

    static Node merge(const Node& l, const Node& r) {
        return Node(l.val + r.val);
    }

    void apply(const Tag& t, int l, int r) {
        if (t.set != -1) val = ((r-l+1)*(t.set)) ;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> color(n);
    for (auto &x : color) cin >> x;

    map<int, deque<int>> idxs;
    // LazySegmentTree<Node, Tag> seg(color);
    DualSegTree<int, Tag> seg(color);

    for (int i = 0; i < n; i++) idxs[color[i]].push_back(i);

    int q; cin >> q;
    while(q--) {
        int c; cin >> c;

        // while(!idxs[c].empty() && seg.query(idxs[c].back(), idxs[c].back()).val != c) idxs[c].pop_back();
        // while(!idxs[c].empty() && seg.query(idxs[c].front(), idxs[c].front()).val != c) idxs[c].pop_front();

        while(!idxs[c].empty() && seg.get(idxs[c].back()) != c) idxs[c].pop_back();
        while(!idxs[c].empty() && seg.get(idxs[c].front()) != c) idxs[c].pop_front();
        
        if(idxs[c].size() <= 1) continue;

        seg.update(idxs[c].front(), idxs[c].back(), c);
    }

    // for (int i = 0; i < n; i++) cout << seg.query(i, i).val << ' ';
    for (int i = 0; i < n; i++) cout << seg.get(i) << ' ';
    cout << '\n';
    
    

    return 0;
}
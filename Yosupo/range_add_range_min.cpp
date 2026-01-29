/**
 * Author:      Lua
 * Problem:     range_add_range_min - Range Add Range Min
 * Link:        https://judge.yosupo.jp/problem/range_add_range_min
 * Status:      ~
 * Created:     29-01-2026 14:25:25
 **/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

struct Tag {
    ll add = 0;
    Tag(ll v = 0) : add(v) {}

    void compose(const Tag& t) {
        add += t.add;
    }
};


struct Node {
    ll val = 0;

    Node(ll v = 0) : val(v) {}

    static Node neutral() { return Node(LLONG_MAX); }

    static Node merge(const Node& l, const Node& r) {
        return Node(min(l.val, r.val));
    }

    void apply(const Tag& t, int l, int r) {
        val += t.add;
    }
};

template<typename NODE, typename TAG>
struct SegTree {
    int N;
    vector<NODE> seg;
    vector<TAG> lazy;

    SegTree(const vector<int>& v) : N(v.size()) {
        seg.resize(4 * N);
        lazy.resize(4 * N);
        build(1, 0, N - 1, v);
    }

    void build(int no, int l, int r, const vector<int>& v) {
        if (l == r) {
            seg[no] = NODE(v[l]); 
            return;
        }
        int m = (l + r) >> 1;
        build(no << 1, l, m, v);
        build((no << 1) | 1, m + 1, r, v);
        seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
    }

    void push(int no, int l, int r) {
        int m = (l + r) >> 1;
        int e = no << 1; 
        int d = e | 1;

        seg[e].apply(lazy[no], l, m);
        seg[d].apply(lazy[no], m + 1, r);

        lazy[e].compose(lazy[no]);
        lazy[d].compose(lazy[no]);

        lazy[no] = TAG(); 
    }

    void update(int no, int l, int r, int a, int b, const TAG& v) {
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            seg[no].apply(v, l, r);
            lazy[no].compose(v);
            return;
        }
        push(no, l, r);
        int m = (l + r) >> 1;
        update(no << 1, l, m, a, b, v);
        update((no << 1) | 1, m + 1, r, a, b, v);
        seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
    }

    NODE query(int no, int l, int r, int a, int b) {
        if (b < l || r < a) return NODE::neutral();
        if (a <= l && r <= b) return seg[no];
        push(no, l, r);
        int m = (l + r) >> 1;
        return NODE::merge(query(no << 1, l, m, a, b),
                           query((no << 1) | 1, m + 1, r, a, b));
    }

    void update(int l, int r, TAG v) { update(1, 0, N - 1, l, r, v); }
    ll query(int l, int r) { return query(1, 0, N - 1, l, r).val; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int q; cin >> q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    SegTree<Node, Tag> seg(arr);
    
    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 0) { // [l,r) += x
            int l, r, x; cin >> l >> r >> x;
            seg.update(l, r-1, { x });
        }

        else if (op == 1) { // min [l,r)
            int l, r; cin >> l >> r;
            cout << seg.query(l, r-1) << '\n'; 
        }
    }
    
    return 0;
}
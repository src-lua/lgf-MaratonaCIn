/**
 * Author:      Lua
 * Problem:     point_set_range_composite - Point Set Range Composite
 * Link:        https://judge.yosupo.jp/problem/point_set_range_composite
 * Status:      ~
 * Created:     29-01-2026 14:29:26
 **/

#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MOD = 998244353;

struct Node {
    ll a, b;

    Node(int a = 1, int b = 0) : a(a), b(b) {}

    static Node neutral() { return Node(); }

    static Node merge(const Node& l, const Node& r) {
        return Node(
            (r.a * l.a) % MOD,
            ((r.a*l.b) % MOD + r.b) % MOD
        );
    }
};

template<typename NODE>
struct SegTree {
    int N;
    vector<NODE> seg;

    SegTree(const vector<NODE>& v) : N(v.size()) {
        seg.resize(4 * N);
        build(1, 0, N - 1, v);
    }

    void build(int no, int l, int r, const vector<NODE>& v) {
        if (l == r) {
            seg[no] = v[l];
            return;
        }
        int m = (l + r) >> 1;
        build(no << 1, l, m, v);
        build((no << 1) | 1, m + 1, r, v);
        seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
    }

    void update(int no, int l, int r, int idx, const NODE& val) {
        if (l == r) {
            seg[no] = val;
            return;
        }
        int m = (l + r) >> 1;
        
        if (idx <= m) update(no << 1, l, m, idx, val);
        else update((no << 1) | 1, m + 1, r, idx, val);

        seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
    }

    NODE query(int no, int l, int r, int a, int b) {
        if (b < l || r < a) return NODE::neutral();
        if (a <= l && r <= b) return seg[no];
        int m = (l + r) >> 1;
        return NODE::merge(query(no << 1, l, m, a, b),
                           query((no << 1) | 1, m + 1, r, a, b));
    }

    void update(int idx, NODE val) { update(1, 0, N - 1, idx, val); }
    NODE query(int l, int r) { return query(1, 0, N - 1, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<Node> arr(n);

    for (auto &x : arr) cin >> x.a >> x.b;
    
    SegTree seg(arr);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 0) { // fp ← cx+d
            int pos, c, d; cin >> pos >> c >> d;
            seg.update(pos, {c, d});
        }

        else if (op == 1) { // query [l,r) fr−1​(fr−2​(...fl​(x)))
            int l, r; cin >> l >> r;
            auto [a,b] = seg.query(l, r-1);

            int x; cin >> x;
            cout << ((a * x) % MOD + b) % MOD << '\n';
        }
    }

    return 0;
}

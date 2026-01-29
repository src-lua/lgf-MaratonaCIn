/**
 * Author:      Lua
 * Problem:     range_set_range_composite - Range Set Range Composite
 * Link:        https://judge.yosupo.jp/problem/range_set_range_composite
 * Status:      ~
 * Created:     29-01-2026 14:30:40
 **/

#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MOD = 998244353;

ll fexpll(ll a, ll n) {
	ll ans = 1;
	while(n) {
		if(n & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return ans;
}

ll inv(ll a) {
    return fexpll(a, MOD-2);
}

struct Tag {
    ll a, b;
    bool empty;
    Tag(ll a = 0, ll b = 0, bool empty = true) : a(a), b(b), empty(empty) {}

    void compose(const Tag& t) {
        if (t.empty) return;
        a = t.a, b = t.b, empty = false;
    }
};

struct Node {
    ll a, b;

    Node(ll a = 1, ll b = 0) : a(a), b(b) {}

    static Node neutral() { return Node(); }

    static Node merge(const Node& l, const Node& r) {
        return Node(
            (r.a * l.a) % MOD,
            ((r.a*l.b) % MOD + r.b) % MOD
        );
    }

    void apply(const Tag& t, int l, int r) {
        if (t.empty) return;
        int sz = r-l+1;
        if (t.a == 1) {
            a = t.a;
            b = (sz * t.b) % MOD;
        }
        else {
            a = fexpll(t.a, sz);
            b = (((a - 1) * inv(t.a-1)) % MOD * t.b) % MOD;
        }
    }
};

template<typename NODE, typename TAG>
struct SegTree {
    int N;
    vector<NODE> seg;
    vector<TAG> lazy;

    SegTree(const vector<NODE>& v) : N(v.size()) {
        seg.resize(4 * N);
        lazy.resize(4 * N);
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

    void push(int no, int l, int r) {
        int m = (l + r) >> 1;
        int e = no << 1, d = e | 1;

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

    void update(int l, int r, TAG v) { v.empty = false; update(1, 0, N - 1, l, r, v); }
    NODE query(int l, int r) { return query(1, 0, N - 1, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<Node> arr(n);

    for (auto &x : arr) cin >> x.a >> x.b;
    
    SegTree<Node, Tag> seg(arr);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 0) {
            int l, r, c, d; cin >> l >> r >> c >> d;
            seg.update(l, r-1, {c, d});
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


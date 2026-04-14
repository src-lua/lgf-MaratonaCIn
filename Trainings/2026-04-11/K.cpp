/**
 * Author:      Lua
 * Problem:     K
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/K
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>

using namespace std; 
using ll = long long;

const int MOD = 1e9+7;

// get sum of sqrs
// update add x
struct Tag {
    ll val;

    Tag(int x = 0) : val(x) {}
    void inline compose(const Tag& t) {
        val = ((val + t.val) % MOD + MOD) % MOD;
    }

};

struct Node {
    ll sum, sum_sqr;

    Node(int x = 0) : sum(x), sum_sqr(x*x) {}
    Node(int x, int y) : sum(x), sum_sqr(y) {}
    static inline Node merge(const Node& l, const Node& r) {
        return Node(
            (((l.sum+r.sum) % MOD) + MOD) % MOD,
            (l.sum_sqr + r.sum_sqr) % MOD
        );
    }
    void inline apply(const Tag&t, int l, int r) {
        sum_sqr = ((sum_sqr + (2*(((sum*t.val%MOD)+MOD)%MOD) % MOD)) % MOD + ((r-l+1)*(t.val*t.val % MOD) % MOD)) % MOD;
        sum = (sum + (((r-l+1) * t.val % MOD) + MOD) % MOD) % MOD;
    }


};

template<typename NODE, typename TAG>
struct LazySegmentTree {
    int N; 
    vector<NODE> seg; 
    vector<TAG> lazy; 

    LazySegmentTree(int n) : N(n), seg(4*n), lazy(4*n) {}
    LazySegmentTree(const vector<int>& v)
    : N(v.size()), seg(4*v.size()), lazy(4*v.size()) {
        build(1, 0, N -1, v);
    }

    void build(int no, int l, int r, const vector<int>& v){
        if (l == r) {
            seg[no] = NODE(v[l]); 
            return; 
        }

        int m = (l + r) >> 1; 
        build(no << 1, l, m, v); 
        build((no << 1) | 1, 1 + m, r, v); 
        seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]); 
    }


    void push(int no, int l, int r) {
        int m = (l + r) >> 1; 
        int e = no << 1, d = e | 1; 

        seg[e].apply(lazy[no], l, m); 
        lazy[e].compose(lazy[no]); 

        seg[d].apply(lazy[no], m + 1, r); 
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
        if (b < l || r < a) return NODE(); 
        if (a <= l && r <= b) return seg[no]; 
        push(no, l, r); 
        int m = (l + r) >> 1; 
        return NODE::merge(query(no << 1, l, m, a, b),
                           query((no<<1) | 1, m+1, r, a, b)); 
    }

    void update(int l, int r, const TAG& v) {update(1,0,N-1,l,r,v);}
    NODE query(int l, int r) {return query(1,0,N-1,l,r);}
}; 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> arr(n); for (auto &x : arr) cin >> x;

    LazySegmentTree<Node, Tag> seg(arr);

    while(q--) {
        char op; cin >> op;

        if (op == 'u') {
            int l, r, x; cin >> l >> r >> x; l--, r--;
            seg.update(l, r, {x});
        }

        else if (op == 'q') {
            int l, r; cin >> l >> r; l--, r--;
            cout << seg.query(l, r).sum_sqr << '\n';
        }
    }

}

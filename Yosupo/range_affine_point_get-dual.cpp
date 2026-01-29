/**
 * Author:      Lua
 * Problem:     range_affine_point_get - Range Affine Point Get
 * Link:        https://judge.yosupo.jp/problem/range_affine_point_get
 * Status:      ~
 * Created:     29-01-2026 14:32:57
 **/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long int; 

const int MOD = 998244353;

struct Tag {
    ll mul = 1;
    ll add = 0;
    Tag(ll m = 1, ll a = 0) : mul(m), add(a) {}

    void compose(const Tag& t) {
        mul = (mul * t.mul) % MOD;
        add = (add * t.mul + t.add) % MOD;
    }
    
    ll apply(ll val) const {
        return (val * mul + add) % MOD;
    }
};

template<typename TAG>
struct DualSegTree {
    int N;
    vector<TAG> lazy;
    vector<ll> leaves;

    DualSegTree(int n) : N(n) {
        lazy.resize(4 * N);
        leaves.resize(N);
    }

    DualSegTree(const vector<int>& v) : N(v.size()) {
        lazy.resize(4 * N);
        leaves.resize(N);
        for(int i=0; i<N; i++) leaves[i] = v[i];
    }

    void push(int no, int l, int r) {
        if (lazy[no].mul == 1 && lazy[no].add == 0) return;

        int m = (l + r) >> 1;
        int e = no << 1; 
        int d = e | 1;

        lazy[e].compose(lazy[no]);
        lazy[d].compose(lazy[no]);

        lazy[no] = TAG();
    }

    void update(int no, int l, int r, int a, int b, const TAG& v) {
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            lazy[no].compose(v);
            return;
        }
        push(no, l, r);
        int m = (l + r) >> 1;
        update(no << 1, l, m, a, b, v);
        update((no << 1) | 1, m + 1, r, a, b, v);
    }

    ll get(int no, int l, int r, int idx) {
        if (l == r) {
            return lazy[no].apply(leaves[idx]);
        }
        push(no, l, r);
        int m = (l + r) >> 1;
        if (idx <= m) return get(no << 1, l, m, idx);
        else return get((no << 1) | 1, m + 1, r, idx);
    }

    void update(int l, int r, TAG t) { update(1, 0, N - 1, l, r, t); }
    ll get(int idx) { return get(1, 0, N - 1, idx); }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    
    DualSegTree<Tag> seg(arr);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 0) { // [l,r) ai = b*ai+c
            int l, r, b, c; cin >> l >> r >> b >> c;

            seg.update(l, r-1, {b, c});
        }

        else if (op == 1) { // Ai
            int i; cin >> i;
            
            cout << seg.get(i) << '\n';
        }
    }

    return 0;
}
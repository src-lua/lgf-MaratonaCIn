/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://codeforces.com/gym/106495/problem/L
 * Status:      AC
 * Created:     10-07-2026 08:10:03
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    ll val;
    Node(ll v = 0) : val(v) {}

    static inline Node merge(const Node&l, const Node& r) {
        return Node(l.val + r.val);
    }

    inline void apply(int v) {
        val += v;
    }
};

template<typename NODE>
struct SegTree {
    int N;
    vector<NODE> seg;

    SegTree(int n) : N(n), seg(4*n) {}

    void update(int no, int l, int r, int idx, int val) {
        if (l == r){
            seg[no].apply(val);
            return;
        }
        int m = (l + r) >> 1;
        if (idx <= m) update(no << 1,l,m,idx,val);
        else update((no<<1)|1,m+1,r,idx,val);
        seg[no]=NODE::merge(seg[no<<1],seg[(no<<1)|1]);
    }

    NODE query(int no, int l, int r, int a, int b) {
        if (b < l || r < a) return NODE();
        if (a <= l && r <= b) return seg[no];
        int m = (l + r) >> 1;
        return NODE::merge(
            query(no<<1,l,m,a,b),
            query((no<<1)|1,m+1,r,a,b)
        );
    }

    void update(int idx, int val) {update(1,0,N-1,idx,val);}
    NODE query(int l, int r) {return query(1,0,N-1,l,r);}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<ll> arr(n); for (auto &x : arr) cin >> x;

    SegTree<Node> seg(n+2);

    ll invs = 0;

    for (int i = 0; i < n; i++) {
        seg.update(arr[i], 1);
        invs += seg.query(arr[i]+1, n+1).val;
    }

    vector<ll> prefix(n+1);
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];
    
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        
        if (op == 1) {
            ll x; cin >> x; x--;
            
            (arr[x] < arr[x+1]) ? invs++ : invs--;
            prefix[x+1] += -arr[x] + arr[x+1];

            swap(arr[x], arr[x+1]);
        }

        if (op == 2) {
            ll x; cin >> x;
            cout << invs + x * (n+1) - 2LL * prefix[x] << '\n';
        }
    }

    return 0;
}

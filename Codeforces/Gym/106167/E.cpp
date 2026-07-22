/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://codeforces.com/gym/106167/problem/E
 * Status:      ~
 * Tags:        
 * Created:     22-07-2026 08:28:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Tag {
    ll add;
    Tag(ll add = 0) : add(add) {};
    void compose(const Tag& t) {
        add += t.add;
    }
};

struct Node {
    ll val;
    Node(ll v = 0) : val(v) {}
    static Node merge(const Node&l, const Node& r) {
        return Node(l.val + r.val);
    }
    void apply(const Tag& t, int l, int r) {
        val += t.add * (r-l+1);
    }
};

template<typename NODE, typename TAG>
struct LazySeg {
    int N;
    vector<NODE> seg;
    vector<TAG> lazy;

    explicit LazySeg(int n)
        : N(n), seg(4*n), lazy(4*n) {}

    template<typename T>
    LazySeg(const vector<T>& v)
        : LazySeg(v.size()) {
        build(1,0,N-1,v);
    }

    template<typename T>
    void build (int no, int l, int r, const vector<T>& v) {
        if (l == r){
            seg[no]= NODE(v[l]);
            return;
        }
        int m = (l+r) >> 1;
        build(no << 1, l, m , v);
        build((no<<1)|1, m+1,r,v);
        seg[no] = NODE::merge(seg[no<<1], seg[(no<<1 )|1]);
    }

    void push(int no, int lo, int hi) {
        int m = (lo + hi) >> 1;
        int l = no << 1, r = l | 1;

        seg[l].apply(lazy[no],lo,m);
        lazy[l].compose(lazy[no]);

        seg[r].apply(lazy[no],m+1, hi);
        lazy[r].compose(lazy[no]);

        lazy[no] = TAG();
    }

    void update(int no, int l, int r, int a, int b, const TAG& v) {
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            seg[no].apply(v,l,r);
            lazy[no].compose(v);
            return;
        }
        push(no, l, r);
        int m = (l + r) >> 1;
        update(no << 1,l,m,a,b,v);
        update((no<<1)|1, m+1, r, a, b, v);
        seg[no] = NODE::merge(seg[no << 1], seg[(no<<1)|1]);
    }

    NODE query(int no, int l, int r, int a, int b) {
        if (b < l  || r < a) return NODE();
        if (a <= l && r <= b) return seg[no];
        push(no,l,r);
        int m = (l+r) >> 1;
        return NODE::merge(query(no<<1,l,m,a,b),
                            query((no<<1)|1,m+1,r,a,b));
    }


    void update(int l, int r, const TAG &v) {
        update(1,0,N-1,l,r,v);
    }
    NODE query(int l, int r) {return query(1,0,N-1,l,r);}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);



    return 0;
}

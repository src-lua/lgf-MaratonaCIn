#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;
using ll = long long;
typedef vector<int> vi;


class SegmentTree {                              // OOP style
    private:
    int n;                                         // n = (int)A.size()
    vi A, st, lazy;                                // the arrays
    
    int l(int p) { return  p<<1; }                 // go to left child
    int r(int p) { return (p<<1)+1; }              // go to right child
    
    int conquer(int a, int b) {
        if (a == -1) return b;                       // corner case
        if (b == -1) return a;
        return min(a, b);                            // RMQ
    }
    
    void build(int p, int L, int R) {              // O(n)
        if (L == R)
        st[p] = A[L];                              // base case
        else {
            int m = (L+R)/2;
            build(l(p), L  , m);
            build(r(p), m+1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }
    
    void propagate(int p, int L, int R) {
        if (lazy[p] != -1) {                         // has a lazy flag
            st[p] += lazy[p];                           // [L..R] has same value
            if (L != R)                                // not a leaf
            lazy[l(p)] = lazy[r(p)] += lazy[p];       // propagate downwards
            else                                       // L == R, a single index
            A[L] += lazy[p];                     // time to update this
            lazy[p] = -1;                              // erase lazy flag
        }
    }
    
    int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return -1;                        // infeasible
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L+R)/2;
        return conquer(RMQ(l(p), L  , m, i          , min(m, j)),
        RMQ(r(p), m+1, R, max(i, m+1), j        ));
    }
    
    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) {                  // found the segment
            lazy[p] += val;                             // update this
            propagate(p, L, R);                        // lazy propagation
        }
        else {
            int m = (L+R)/2;
            update(l(p), L  , m, i          , min(m, j), val);
            update(r(p), m+1, R, max(i, m+1), j        , val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = conquer(lsubtree, rsubtree);
        }
    }
    
    public:
    SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}
    
    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    
    void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
    
  int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};

const int INF = INT_MAX;
const int mx = 1e6+2;

class SegmentTreeSum {
public:
vector<int> seg, lazy;
    // Lazy SegTree
    SegmentTreeSum() {
        seg = vector<int>(4*mx, 0);
        lazy = vector<int>(4*mx,0);
    }
        
    void unlazy(int no, int l, int r){
        if(lazy[no] == 0) return;
    
        int m=(l+r)/2, e=no*2, d=no*2+1;
    
        seg[no] += (r-l+1) * lazy[no];
    
        if(l != r){
            lazy[e] += lazy[no];
            lazy[d] += lazy[no];
        }
    
        lazy[no] = 0;
    }
    
    int query(int no, int l, int r, int a, int b){
        unlazy(no, l, r);
        if(b <  l || r <  a) return 0;
        if(a <= l && r <= b) return seg[no];
        
        int m=(l+r)/2, e=no*2, d=no*2+1;
    
        return query(e, l, m, a, b) + query(d, m+1, r, a, b);
    } 
    
    void update(int no, int l, int r, int a, int b, int v){
        unlazy(no, l, r);
        if(b <  l || r <  a) return;
        if(a <= l && r <= b)
        {
            lazy[no]+= v;
            unlazy(no, l, r);
            return;
        }
    
        int m=(l+r)/2, e=no*2, d=no*2+1;
    
        update(e, l,   m, a, b, v);
        update(d, m+1, r, a, b, v);
    
        seg[no] = seg[e] + seg[d];
    }
};
    
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr(1e6+2);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = i;
}

    SegmentTree seg(arr);
    SegmentTreeSum segsum;

    // segsum.seg = vector<int>(4*mx, 0);
    // segsum.lazy = vector<int>(4*mx,-1);

    int q; cin >> q;

    vector<pair<string, pair<int,int>>> querys;

    string op; int a, b;
    for (int i = 0; i < q; i++) {
        cin >> op;
        
        if (op == "+") {
            cin >> a >> b;
            seg.update(a, a+b-1, 1e6+10);
            segsum.update(1,1,1e6+2, a, a+b-1, 1);
        }
        else if (op == "?") {
            cin >> a;
            b = seg.RMQ(a, 1e6+1);
            cout << segsum.query(1,1,1e6+2,a, b) << endl;
        }
        else if (op == "-") {
            cin >> a;
            auto [x, y] = querys[a].second;
            seg.update(x, x+y-1, -1e6+10);
            segsum.update(1,1,1e6+2, a, a+b-1, -1);
        }

        querys.push_back({op, {a, b} });
    }
    

    return 0;
}
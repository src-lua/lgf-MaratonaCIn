/*                                          
  Lucas Guimarães Fernandes </lgf_cin>
  MaratonaCIn @ CIn - UFPE

  [Magnets](https://codeforces.com/gym/102860/problem/L)
  Rating: ---
  Tags: SegTree Lazy; Math;
  Status: Accepted
*/
#include <bits/stdc++.h>

#define endl '\n'
using ll = long long;

using namespace std;

int n, q;
const int INF = INT_MAX;
const int mx = 2e5+5;

class segtree {
public:
    // Lazy SegTree
    segtree() {
        seg = vector<ll>(4*mx);
        lazy = vector<ll>(4*mx,-1);
    }

    vector<ll> seg, lazy;

    void unlazy(int no, int l, int r){
        if(lazy[no] == -1) return;
    
        int m=(l+r)/2, e=no*2, d=no*2+1;
    
        seg[no] = (r-l+1) * lazy[no];
    
        if(l != r){
            lazy[e] = lazy[no];
            lazy[d] = lazy[no];
        }
    
        lazy[no] = -1;
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
            lazy[no] = v;
            unlazy(no, l, r);
            return;
        }
    
        int m=(l+r)/2, e=no*2, d=no*2+1;
    
        update(e, l,   m, a, b, v);
        update(d, m+1, r, a, b, v);
    
        seg[no] = seg[e] + seg[d];
    }
    
    void build(int no, int l, int r, vector<int> &lista){
        if(l == r){ seg[no] = lista[l-1]; return; }
    
        int m=(l+r)/2, e=no*2, d=no*2+1;
    
        build(e, l,   m, lista);
        build(d, m+1, r, lista);
        
        seg[no] = seg[e] + seg[d];
    }
};

segtree cordx, cordy, pos;

ll getx(int a) {
    if (pos.query(1,1, n,a,a) == 0) {
        return cordx.query(1,1, n, a,a);
    } 
    else {
        return a - cordy.query(1,1, n, a,a);
    }
}

ll gety(int a) {
    if (pos.query(1,1, n, a,a) == 1) {
        return cordy.query(1,1, n, a,a);
    } 
    else {
        return a - cordx.query(1,1, n, a,a);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    n++;

    for (int i = 1; i < n; i++) {
        cordx.update(1,1, n,i,i,i);
    }
    
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b;
            if (a == b) continue;
            int x = getx(a);
            int y = gety(a);
            if(getx(a) == getx(b)) {
                pos.update(1,1, n,a, b, 1);
                cordy.update(1,1, n,a, b, y);
            }
            else {
                pos.update(1,1, n,a, b, 0);
                cordx.update(1,1, n,a, b, x);
            }
        }
        else if (t == 2) {
            int a; cin >> a;
            cout << getx(a) << ' ' << gety(a) << endl;
        }
    }
    

    return 0;
}
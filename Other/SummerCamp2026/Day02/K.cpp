/**
 * Author:      Lua
 * Problem:     K
 * Link:        https://vjudge.net/contest/782309#problem/K
 * Status:      AC
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;
const int INF = 2e9;
struct SegTree {
    vector<int> seg;
    vector<int> lazy;
    int N; 

    SegTree(int n) : N(n){ seg.assign(4*n, 0); lazy.assign(4*n, -1); }

    void unlazy(int no, int l, int r){
        if(lazy[no] == -1) return;
        
        seg[no] = lazy[no];

        if(l != r) lazy[no*2] = lazy[no*2+1] = lazy[no];

        lazy[no] = -1;
    }

    int query(int no, int l, int r, int a, int b){
        unlazy(no, l, r);
        if(b <  l || r <  a) return INF;
        if(a <= l && r <= b) return seg[no];
        int m = (l+r)/2, e=no*2, d=e+1;
        return min(query(e, l, m, a, b), query(d, m+1, r, a, b));
    }   
    void update(int no, int l, int r, int a, int b, int v){
        unlazy(no, l, r);
        if(b <  l || r <  a) return;
        if(a <= l && r <= b){
            lazy[no] = v;
            return unlazy(no, l, r);
        };
        int m = (l+r)/2, e=no*2, d=e+1;

        update(e, l, m, a, b, v);
        update(d, m+1,r,a, b, v);

        seg[no] = min(seg[e], seg[d]);
    }

    int query(int l, int r){
        return query(1, 0, N-1, l, r);
    }
    void update(int l, int r, int v){
        update(1, 0, N-1, l, r, v);
    }
};
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> val(n);
    for(int i=0;i<n;i++)cin>>val[i];
    SegTree seg(n);
    for(int i=0;i<n;i++)seg.update(i, i, val[i]);
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;r--;
        cout<<seg.query(l, r)<<"\n";
    }
}
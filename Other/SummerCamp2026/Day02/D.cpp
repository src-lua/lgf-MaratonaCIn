/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://vjudge.net/contest/782309#problem/D
 * Status:      AC
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

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
        if(b <  l || r <  a) return -1;
        if(a <= l && r <= b) return seg[no];
        int m = (l+r)/2, e=no*2, d=e+1;
        return max(query(e, l, m, a, b), query(d, m+1, r, a, b));
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

        seg[no] = max(seg[e], seg[d]);
    }

    int query(int l, int r){
        return query(1, 0, N-1, l, r);
    }
    void update(int l, int r, int v){
        update(1, 0, N-1, l, r, v);
    }
};

const int MAXN = 500000 + 10;

int tin[MAXN], tout[MAXN];
vector<int> g[MAXN];

int timer = 0;
void dfs(int u, int p){
    tin[u] = ++timer;
    for(auto v : g[u])
        if(v != p)
            dfs(v, u);
    tout[u] = timer;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    int n; cin >> n;

    for(int i=1, u, v; i<n; i++){
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);

    SegTree anc(timer+1), desc(timer+1);

    int opa = 1;
    desc.update(0, timer, opa++);

    int q; cin >> q;
    while(q--){
        int op, v;
        cin >> op >> v; v--;

        if(op == 1){ //fill
            anc.update(tin[v], tout[v], opa++);
        }
        if(op == 2){ //empty
            desc.update(tin[v], tin[v], opa++);
        }
        if(op == 3){
            cout << (anc.query(tin[v], tin[v]) > desc.query(tin[v], tout[v])) << endl;
        }
    }

}
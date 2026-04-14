/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/F
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <class T>
struct Point {
    typedef Point P;
    T x, y;

    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    explicit Point(pair<T,T> p) : x(p.first), y(p.second) {}

    P operator-(P p) const {return P(x-p.x, y-p.y);}
    P operator+(P p) const {return P(x+p.x, y+p.y);}

    T cross(P p) const {return x*p.y-y*p.x;}
    T cross(P a, P b) const {return P(a-*this).cross(b-*this);}
};

template<class P>
bool isColinear(P a, P b, P c) {
    return a.cross(b, c) == 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n; 
    vector<pair<ll, ll>> pos(n); 
    for (auto &[x, y] : pos) cin >> x >> y; 

    ll ans = 0; 
    for (int i = 0  ; i < n; i++) { Point<ll> pi(pos[i]);
    for (int j = i+1; j < n; j++) { Point<ll> pj(pos[j]); 
    for (int k = j+1; k < n; k++) { Point<ll> pk(pos[k]);  
        if (isColinear(pi,pj,pk)) continue; 
    for (int l = k+1; l < n; l++) { Point<ll> pl(pos[l]);  
        if (!isColinear(pi,pj,pl) && 
            !isColinear(pj,pk,pl) &&
            !isColinear(pi,pk,pl))ans++; 
    } } } }   

    cout << ans << '\n'; 
    return 0;
}
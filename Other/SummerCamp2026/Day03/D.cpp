/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://vjudge.net/contest/782311#problem/D
 * Status:      AC
 * Created:     29-01-2026 11:15:23
 **/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define pb push_back



const int MAXN = 2e5+5;

ll bit[MAXN];
ll n,q;
ll query(ll i){
    ll ret = 0;
    for(; i > 0; i-= (i & -i)){
        ret+=bit[i];
    }
    return ret;
}

void increment(ll i, ll v){
    for(; i<=n; i+= (i&-i)){
        bit[i]+=v;
    }
}

void solve(){

    cin>>n>>q;


    for(int i = 1; i<=n; i++){
        ll x; cin>>x;
        increment(i,x);
    }


    while(q--){
        ll op; cin>>op;

        if(op%2){
            ll k, u; cin>>k>>u;
            ll at = query(k)-query(k-1);
            ll diff = u-at;
            increment(k, diff);
        }else{
            ll a, b; cin>>a>>b;
            cout<<query(b)-query(a-1)<<endl;
        }
    }





}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1;
    //cin>>t;
    while(t--)solve();
}

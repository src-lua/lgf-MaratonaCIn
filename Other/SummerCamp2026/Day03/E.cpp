/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://vjudge.net/contest/782311#problem/E
 * Status:      AC
 * Created:     29-01-2026 11:15:23
 **/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define pb push_back
vector<vector<ll>>adj(1e6+6);

void dfs(ll u, ll p, ll d, vector<ll>&de){
    de[u]=d;
    for(auto v : adj[u]){
        if(p!=v)dfs(v,u,d+1,de);
    }
}

void solve(){

    ll n; cin>>n;
    
    for(int i = 0; i < n-1; i++){
        ll a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
if(n==1){
cout<<0<<endl;
return;
}
    vector<ll> depth1(n+1);
    dfs(1,-1,0,depth1);
    vector<ll>depth2(n+1);
    ll maior = -1;
    ll maiori = -1;
    for(int i = 1; i<=n; i++){
        if(depth1[i]>maior){
            maiori = i;
            maior = depth1[i];
        }
    }
    dfs(maiori,-1,0,depth2);
    ll ans = 0;
    for(auto& x : depth2)ans = max(x,ans);
    cout<<ans<<endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1;
    //cin>>t;
    while(t--)solve();
}

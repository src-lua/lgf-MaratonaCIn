#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
vector<pair<int,int>> v;

ll solve(){
    
    
    sort(v.begin(),v.end());
    
    vector<bool> vis(n,false);
    
    ll ret =0;
    
    for(int i=0;i<n;i++){
        
        if(vis[i] || v[i].second == i) continue;
        
        int cnt =0, j=i;
        
        while(!vis[j]){
            vis[j] = true;
            j = v[j].second;
            cnt++;
        }
        
        if(cnt>0){
            ret+=cnt-1;
        }
        
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin>>n;
    
    ll ans =0;
    
    v = vector<pair<int,int>> (n);
    
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i;
    }
    
    ans+= solve();
    
    v = vector<pair<int,int>> (n);

    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i;
    }
    
    ans+=solve();
    
    cout<<ans<<"\n";
}
/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://vjudge.net/contest/782311#problem/A
 * Status:      AC
 * Created:     29-01-2026 11:15:23
 **/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll>a(n);
    ll ans= 0;
    for(auto& x : a){
        cin>>x;
        ans^=x;

    }
    if(ans==0){
        cout<<"second"<<endl;
    }else{
        cout<<"first"<<endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1;
    cin>>t;
    while(t--)solve();
}

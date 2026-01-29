/**
 * Author:      Lua
 * Problem:     N
 * Link:        https://vjudge.net/contest/782311#problem/N
 * Status:      AC
 * Created:     29-01-2026 11:15:23
 **/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define pb push_back



const int MAXN = 2e5+5;
#define endl '\n'

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

	ll n; cin>>n;
	if(n%3){
		cout<<"First"<<endl;
	}else{
		cout<<"Second"<<endl;
	}

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1;
    cin>>t;
    while(t--)solve();
}

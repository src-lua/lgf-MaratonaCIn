/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://vjudge.net/contest/782311#problem/F
 * Status:      WA
 * Created:     29-01-2026 11:15:23
 **/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define pb push_back

ll n;
set<ll>primos_fake;
vector<ll>primos;
vector<ll>ord;
ll qnt;
map<ll,ll>p_i;

vector<vector<pii>>primos_quant;
map<vector<vector<pii>>, bool>state; //true se ganha


bool rec(vector<vector<pii>>&atual){
    if(state.count(atual))return state[atual];
    bool perdedor = true;
    ll maxk = 0;
    for(auto& x : atual){
        for(auto& y : x)maxk=max(maxk,y.second);
    }
    for(int i = 0; i < qnt; i++){
        ll p = 1;
        for(int k = 1; k <= maxk; k++){
            if(p<=1e9)p*=ord[i];
            vector<vector<pii>>newstate = atual;
            bool change = false;
            for(int cara = 0; cara < n; cara++){
                for(auto& x : newstate[cara]){
                    if(x.first==i && x.second >= k){
                        x.second-=k;
                        change=true;
                    }
                }
            }
            if(!change)continue;
            perdedor = perdedor and rec(newstate);
            if(!perdedor) return state[atual] = true;
        }
    }
   return state[atual] = false;


}


void solve(){

    cin>>n;
    vector<ll>a(n);
    for(auto& x : a)cin>>x;
    vector<vector<pii>>fim(n);
    state[fim]=false;
    for(auto x : a){

        primos_quant.pb({});
        for(int i = 2; i*i<=x; i++){
            ll q = 0;
            while(x%i==0){
                q++;
                x/=i;
            }
            if(q){
                primos_fake.emplace(i);
                primos_quant.back().pb({i,q});
            }
        }
        if(x>1){
            primos_fake.emplace(x);
            primos_quant.back().pb({x,1});
        }
    }
    for(auto& x : primos_fake)primos.pb(x);
    qnt = primos.size();
    for(int i =0; i < qnt; i++){
        ord.pb(primos[i]);
        p_i[primos[i]=i];
    }
    for(int i = 0; i < n; i++){
        for(auto & y : primos_quant[i])y.first=p_i[y.first];
    }

    if(rec(primos_quant)){
        cout<<"Mojtaba"<<endl;
    }else{
        cout<<"Arpa"<<endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}

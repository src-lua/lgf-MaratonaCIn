/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://vjudge.net/contest/784977#problem/A
 * Status:      AC
 * Created:     28-01-2026 16:28:16
 **/

#include <bits/stdc++.h>
#define ll long long
#define ALL(x) x.begin(), x.end()
#define vi vector<int>
#define int ll
#define INF 0x3f3f3f3f3f3f3f
using namespace std;



vi zf(vi & s){

    int n = s.size();
    vi z(n,0);

    for(int i = 1,l = 0, r = 0;i < n;i++){

        if(i <=r) z[i] = min(z[i - l],r- i + 1);

        while(z[i] + i < n && s[z[i]] == s[i + z[i]]) z[i]++;

        if(r < i + z[i] - 1) l = i, r = i + z[i] -1;

    }
    return z;
}




signed main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n, w; cin >> n >> w;
    vi a(n),b(w);
    for(auto & x : a) cin >> x;
    for(auto & x : b) cin >> x;

    vi da,db;
    for(int i = 0; i < n - 1;i++){
        da.push_back(a[i + 1] - a[i]);
    }

    for(int i = 0; i < w - 1;i++){
        db.push_back(b[i + 1] - b[i]);
    }

    // for(auto x : da){
    //     cout << x << " ";
    // }
    // cout << endl;
    // for(auto x : db){
    //     cout << x << " ";
    // }
    // cout << endl;
    auto aux = db;
    aux.push_back(INF);
    for(auto x : da){
        aux.push_back(x);
    }

    auto z = zf(aux);
    int ans = 0;
    for(auto x : z){
        if(x == w - 1) ans++;
    }
    cout << ans << endl;


    
}
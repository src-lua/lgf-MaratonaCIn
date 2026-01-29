/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://vjudge.net/contest/783478#problem/D
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>
using ll = long long;
#define int ll
#define vi vector<int>
using namespace std;
const int inf = 1e9;
#define MAXN 100010
vi grafo[MAXN];
bool vis[MAXN];
vi ciclo;
bool to = 0;
void dfs(int u, int p){
    // cout << u << " " << p << endl;
    vis[u] = 1;
    for(auto v : grafo[u]){

        if(vis[v] && v != p){
            ciclo.push_back(v);
            ciclo.push_back(u);
            to = 1;
            return;
        }
        if(vis[v]) continue;
        dfs(v,u);
        if(to){
            ciclo.push_back(u);
            if(u == ciclo[0]){
                to = 0;
            }
            return;
        }

        if(ciclo.size()) return;

    }
}

void solve() {
	
    int n,m; cin >> n >> m;

    while(m--){
        int u,v; cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    for(int i = 1; i <=n;i++){
        if(vis[i]) continue;
        dfs(i,-1);
        if(ciclo.size()) break;
    }

    if(ciclo.size()){   
        cout << ciclo.size() << endl;

        for(auto x : ciclo){
            cout << x << " ";
        }
        cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
        
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	// freopen("in.txt", "r", stdin);
	solve();
    return 0;
}

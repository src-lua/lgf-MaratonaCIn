/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://vjudge.net/contest/782311#problem/H
 * Status:      AC
 * Created:     29-01-2026 11:15:23
 **/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;
const int MAXLG = 20;

vector<int> g[MAXN];
int bl[MAXLG][MAXN], lvl[MAXN];

void dfs(int u, int p, int l=0){
	lvl[u] = l;
	bl[0][u] = p;
    //cout<<u<<" "<<v<<endl
	for(auto v : g[u]) {if(v != p){
		dfs(v, u, l+1);}}
}

void buildBL(int N){
	for(int i=1; i<MAXLG; i++)
		for(int u=0; u<N; u++)
			bl[i][u] = bl[i-1][bl[i-1][u]];	
}

int lca(int u, int v){
	if(lvl[u] < lvl[v]) swap(u, v);

	for(int i=MAXLG-1; i>=0; i--)
		if(lvl[u] - (1<<i) >= lvl[v])
			u = bl[i][u];
	
	if(u == v) return u;

	for(int i=MAXLG-1; i>=0; i--)
		if(bl[i][u] != bl[i][v])
			u = bl[i][u],
			v = bl[i][v];

	return bl[0][u];
}

const int MXN = 5e4+10;
vector<pair<int,int>>memo(MXN, pair{-1,-1});
pair<int,int> get(vector<int>& coins, int i) {
    if (memo[i] != pair{-1,-1}) return memo[i];

    int odd = 0, even = 0;
    for (auto e : g[i]) {
        if (lca(e, i) == i) {
            auto[a,b] = get(coins, e);
            odd ^= a, even ^= b;
        }
    }

    if (coins[i] != 0) {
        if (lvl[i] % 2 == 1) odd ^= coins[i];
        else even ^= coins[i];
    }

    return memo[i] = {odd, even};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> coins(n);
    for (auto &x : coins) cin >> x;

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }

    dfs(0, -1);
    buildBL(n);
    int ans = 0;

    auto [l, r] = get(coins, 0);

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v; u--, v--;

        if (lca(u, v) == u) cout << "INVALID\n";
        else {
            auto [a, b] = get(coins, u);
            if (lvl[bl[0][u]] % 2 != lvl[v] % 2) {
                if (l^a^b) cout << "YES\n";
                else cout << "NO\n"; 
            }
            else {
                if (l) cout << "YES\n";
                else cout << "NO\n";
            }
        } 
    }
    

    return 0;
}

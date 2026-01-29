/**
 * Author:      Lua
 * Problem:     I
 * Link:        https://vjudge.net/contest/782309#problem/I
 * Status:      AC
 * Created:     29-01-2026 11:06:02
 **/

 #include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;
const int INF = 2e9;

vector<vector<pair<int, int>>> gf;
vector<vector<int>> nxt;

int djs(int ori){
    vector<int> dst(gf.size(), INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    heap.push({0, ori});
    dst[ori] = 0;

    while(!heap.empty()){
        auto [dt, u] = heap.top(); heap.pop();
        if(dst[u] < dt) continue;

        for(auto [v, tm] : gf[u]){
            int trns = *lower_bound(nxt[tm].begin(), nxt[tm].end(), dt) - dt + 1;

            if(dst[v] > dst[u] + trns){
                // cout << u + 1 << " " << v + 1 << " | " << dt << "at wait" << trns << endl;
                dst[v] = dst[u] + trns;
                heap.push({dst[v], v});
            }
        }
    }

    // for(auto &x : dst) cout << x << " "; cout << endl;

    if(dst.back() == INF)return -1;
    else return dst.back();    
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, t;
    cin>>n>>t;
    
    gf.resize(n);
    nxt.resize(t);

    for(int i=0;i<t;i++){
        int m;
        cin>>m;
        for(int j=0, u, v;j<m;j++){
            cin>>u>>v;
            u--;v--;

            gf[u].push_back({v, i});
            gf[v].push_back({u, i});
        }
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int tp; cin>>tp;
        tp--;

        nxt[tp].push_back(i);
    }

    for(int i=0;i<t;i++) nxt[i].push_back(INF + 1);

    cout << djs(0) << endl;
}
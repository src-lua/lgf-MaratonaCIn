#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n;
const int MXN = 10e5+1;

vector<int> dist(MXN+1, 0);
vector<vector<int>> adj(MXN+1);

int getdist(int idx) {
    if (dist[idx] != 0) return dist[idx];

    int answ = 0;

    for (auto e: adj[idx]) {
        answ = max(answ, getdist(e));
    }

    return dist[idx] = answ+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> n >> m;
    
    
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    int answ = 0;
    for (int i = 1; i <= n; i++) {
        answ = max(answ, getdist(i));
    }
    
    cout << answ-1;
   
    return 0;
}
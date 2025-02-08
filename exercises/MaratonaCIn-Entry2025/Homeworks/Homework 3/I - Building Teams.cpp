#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> adj(10e5+2);
vector<bool> colored(10e5+2, false);
vector<bool> color(10e5+2, false);
 
 
bool bipart(int e) {
    colored[e] = true;
    for(auto u:adj[e]) {
        if (!colored[u]) {
            color[u] = !color[e];
            colored[u] = true;
            if (!bipart(u)) return false;
        }
        else if (color[e] == color[u]) return false;
    }
    return true;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int people, friendship;
    int x, y;
 
    cin >> people; cin >> friendship;
 
 
    for (int i = 0; i < friendship; i++) {
        cin >> x; cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
 
    for (int i = 1; i < people+1; i++) {
        if (!colored[i]) {
            if (!bipart(i)) {
                cout << "IMPOSSIBLE";
                return 0;
            }   
        }
    }
 
    for (int i = 1; i < people+1; i++) {
        if (!color[i]) cout << "1 ";
        else cout << "2 ";
    }

    return 0;
}     
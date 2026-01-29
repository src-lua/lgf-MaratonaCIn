/**
 * Author:      Lua
 * Problem:     P
 * Link:        https://vjudge.net/contest/782309#problem/P
 * Status:      AC
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;
const int mxn = 1000, mxm = 1000;
int n, m;
ll grid[mxn][mxm];
bool vis[mxn][mxm];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool inside(int x, int y){
    return (x >= 0 and x < n and y >= 0 and y < m);
}

ll dfs(int x, int y){
    vis[x][y] = true;
    ll vol = grid[x][y];
    for(int i=0;i<4;i++){
        int nx = dx[i] + x, ny = dy[i] + y;
        if(inside(nx, ny) and !vis[nx][ny] and grid[nx][ny] != 0)vol += dfs(nx, ny);
    }
    return vol;
    
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            vis[i][j] = false;
        }
    }
    ll resp = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] and grid[i][j] != 0)resp = max(resp, dfs(i, j));
        }
    }
    cout<<resp<<"\n";
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();

}
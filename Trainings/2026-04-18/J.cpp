/**
 * Author:      Lua
 * Problem:     J
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/100971/problem/J
 * Status:      AC
 * Created:     07-06-2026 18:21:36
 **/

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<string> board(n); for (auto &row: board) cin >> row;

    vector<vector<int>> adj(n*m);
    auto plain = [&](int x, int y) { return x*m + y; };

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (board[i][j] == '#') continue;
        for (int d = 0; d < 4; d++) {
            int x = i + dx[d], y = j + dy[d];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (board[x][y] == '#') continue;
            adj[plain(i,j)].push_back(plain(x,y)); 
        }
    }

    int ones = 0, twos = 0, more = 0;
    for (auto &adju : adj) {
        if (adju.size() == 1) ones++; else
        if (adju.size() == 2) twos++; else
        if (adju.size() >= 3) more++;
    }
    
    cout << ((ones == 2 && more == 0) ? "NO\n": "YES\n");

    return 0;
}

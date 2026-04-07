/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/606592/problem/E
 * Status:      AC
 * Created:     06-04-2026 21:45:52
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (auto &r : board) for (auto &x : r) cin >> x;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] + (board[i][j]%2 == (i+j)%2) << ' ';
        } cout << '\n';
    }

    return 0;
}

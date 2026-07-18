/**
 * Author:      Lua
 * Problem:     E - Minesweeper
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/E
 * Status:      ~
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy[8] = {-1,  0,  1, -1,  1, -1,  0,  1};

bool isValid(int n, int m, const vector<vector<int>>& board, int r, int c, int k) {
    bool flag = false;
    for (int d = 0; d < 8; d++) {
        int x = r + dx[d], y = c + dy[d];
        if (!(x >= 0 && x < n && y >= 0 && y < m)) continue;
        
        if (board[x][y] >= k) return false;
        if (board[x][y] != 0) flag = true;
    }
    return flag; 
}

void backtrack(int r, int c, int n, int m, int k, vector<vector<int>>& board, vector<pair<int,int>>& bombs, int& ans) {
    if (r == n) return ans = max(ans, (int)bombs.size()), void();

    int next_r = r;
    int next_c = c + 1;
    if (next_c == m) {
        next_r = r + 1;
        next_c = 0;
    }

    backtrack(next_r, next_c, n, m, k, board, bombs, ans);
    
    for (int d = 0; d < 8; d++) {
        int nx = r + dx[d], ny = c + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) board[nx][ny]++;
    } bombs.push_back({r, c}); 

    if (isValid(n, m, board, r, c, k)) {
        backtrack(next_r, next_c, n, m, k, board, bombs, ans);
    }

    for (int d = 0; d < 8; d++) {
        int nx = r + dx[d], ny = c + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) board[nx][ny]--;
    } bombs.pop_back();
}

void solve() {
    int n, m, k; 
    cin >> n >> m >> k;

    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<pair<int,int>> bombs;

    int ans = 0;
    backtrack(0, 0, n, m, k, board, bombs, ans);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}

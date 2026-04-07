/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/606592/problem/E
 * Status:      TLE
 * Created:     06-04-2026 21:45:52
 **/

#include <bits/stdc++.h>

using namespace std;

// L U R D
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int n, m;

bool backtrack(vector<vector<int>>& board, int i, int j) {
    if (i >= board.size()) return true;

    vector<int> ds;
    bool flag = false;

    for (int d = 0; d < 4; d++) {
        int x = i + dx[d], y = j + dy[d];
        if (!(x >= 0 && x < n && y >= 0 && y < m)) continue;

        if (board[x][y] == board[i][j]) ds.push_back(d);
        if (board[x][y] == board[i][j]+1 && d < 2) flag = true;
    }
    
    int next_i = (j+1 >= m ? i+1 : i);
    int next_j = (j+1 >= m ? 0 : j+1);
    
    if (ds.size() == 0) {
        if (backtrack(board, next_i, next_j)) return true; 

        board[i][j]++;
        bool ans = backtrack(board, next_i, next_j);
        if (ans) return ans;
        board[i][j]--;
        
        return ans;
    }
    
    if (ds.front() <= 1) {
        if (flag) return false;
        
        board[i][j]++;
        bool ans = backtrack(board, next_i, next_j);
        if (ans) return ans;
        board[i][j]--;
        return ans;
    }
      
    if (backtrack(board, next_i, next_j)) return true;
    
    if (flag) return false;
    
    board[i][j]++;
    bool ans = backtrack(board, next_i, next_j);
    if (ans) return ans;
    board[i][j]--;
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (auto &r : board) for (auto &x : r) cin >> x;
    
    assert(backtrack(board, 0, 0) == true);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        } cout << '\n';
    }

    return 0;
}

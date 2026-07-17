/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/100971/problem/A
 * Status:      AC
 * Created:     07-06-2026 18:21:36
 **/

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using graph = vector<string>;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

void bfs(graph& board, pii start, vector<vector<bool>>& visited) {
    int n = board.size(), m = board.back().size();
    queue<pii> q; q.push(start);

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int x = i + dx[d], y = j + dy[d];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (board[x][y] == '#') continue;
            if (visited[x][y]) continue;
            visited[x][y] = true; q.emplace(x, y);
        }
    }
}

bool check(graph& board) {
    int n = board.size(), m = board.back().size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool flag = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (board[i][j] == '#') continue;
        if (visited[i][j]) continue;
        if (flag) visited[i][j] = true, bfs(board, {i,j}, visited), flag = false; 
        else return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    graph board(n); for (auto &row : board) cin >> row;

    vector<vector<bool>> reachable(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (board[i][j] != '.') continue;
        if (reachable[i][j]) continue;
        bfs(board, {i, j}, reachable);
    }

    vector<pii> marks;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (board[i][j] == '?') {
        if (reachable[i][j]) marks.emplace_back(i,j), board[i][j] = '.';
        else board[i][j] = '#';
    }

    if (!check(board)) {
        cout << "Impossible\n";
        return 0;
    }

    vector<pii> necessary, others;

    for (auto &[i, j] : marks) {
        board[i][j] = '#';
        (!check(board) ? necessary : others).emplace_back(i,j);
        board[i][j] = '.';
    };

    for (auto &[i, j] : others) board[i][j] = '#';
    for (auto &[i, j] : others) for (int d = 0; d < 4; d++) {
        int x = i + dx[d], y = j + dy[d];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (board[x][y] == '.') {
            cout << "Ambiguous\n";
            return 0;
        }
    }
   
    if (!check(board)) {
        cout << "Ambiguous\n";
        return 0;
    }

    for (auto &row : board) cout << row << '\n';

    return 0;
}
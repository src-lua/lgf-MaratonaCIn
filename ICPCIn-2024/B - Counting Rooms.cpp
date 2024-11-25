#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

// Time Complexity: O(V + E)
void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, pii start) {
    queue<pii> operation_order;

    visited[start.first][start.second] = true;
    operation_order.push(start);

    while (!operation_order.empty()) {
        auto [i, j] = operation_order.front();
        operation_order.pop();

        for (int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];
            
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
            if (board[x][y] == '#' || visited[x][y]) continue;

            visited[x][y] = true;
            operation_order.push({x,y});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col; char c;
    
    cin >> row >> col;
    
    vector<vector<char>> board(row, vector<char>(col));
    
    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(c);
            board[i][j] = c;
        }
    }

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int answ = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] != '#') {
                if (!visited[i][j]) {
                    bfs(board, visited, {i,j});
                    answ++;
                }
            }
        }
    }

    cout << answ;

    return 0;
}
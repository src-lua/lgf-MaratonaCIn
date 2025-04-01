#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

// Time Complexity: O(V + E)
int bfs(vector<vector<int>>& board, vector<vector<bool>>& visited, pii start) {
    queue<pii> operation_order;

    int volume = 0;

    visited[start.first][start.second] = true;
    operation_order.push(start);

    while (!operation_order.empty()) {
        auto [i, j] = operation_order.front();
        operation_order.pop();
        volume += board[i][j];

        for (int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];
            
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
            if (board[x][y] == 0 || visited[x][y]) continue;


            visited[x][y] = true;
            operation_order.push({x,y});
        }
    }

    return volume;
}

int solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col; char c;
    
    cin >> row >> col;
    
    vector<vector<int>> board(row, vector<int>(col));
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> board[i][j];
        }
    }

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int answ = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] != 0) {
                if (!visited[i][j]) {
                    answ = max(answ, bfs(board, visited, {i,j}));
                    
                }
            }
        }
    }

    cout << answ << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
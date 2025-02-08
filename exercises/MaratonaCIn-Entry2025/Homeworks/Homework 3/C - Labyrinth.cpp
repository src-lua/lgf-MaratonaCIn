#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

// Time Complexity: O(V + E)
void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<vector<pii>>& parents, pii start) {
    queue<pii> operation_order;


    visited[start.first][start.second] = true;
    parents[start.first][start.second] = {start.first, start.second};
    operation_order.push(start);

    while (!operation_order.empty()) {
        auto [i, j] = operation_order.front();
        operation_order.pop();

        for (int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];
            
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
            if (board[x][y] == '#' || visited[x][y]) continue;

            parents[x][y] = {i, j};
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
    
    pii start, end;

    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(c);
            if (c == 'A') start = {i, j};
            else if (c == 'B') end = {i, j};
            board[i][j] = c;
        }
    }

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<vector<pii>>  parents(row, vector<pii>(col, {-1, -1}));

    bfs(board, visited, parents, start);

    pii curr = end;
    stack<char> answ;

    if (!visited[end.first][end.second]) {
        cout << "NO\n";
        return 0;
    }

    while(curr != start) {
        auto [x, y] = curr;
        auto [xp, yp] = parents[x][y];
        
        if (x > xp) answ.push('D'); else
        if (x < xp) answ.push('U'); else
        if (y > yp) answ.push('R'); else
        if (y < yp) answ.push('L');

        curr = parents[curr.first][curr.second];
    }

    cout << "YES\n" << answ.size() << '\n';
    
    while(!answ.empty()) {
        cout << answ.top();
        answ.pop();
    }
    cout << '\n';

    return 0;
}
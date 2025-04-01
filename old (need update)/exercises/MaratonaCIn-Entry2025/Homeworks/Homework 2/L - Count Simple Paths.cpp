#include <bits/stdc++.h>

#define endl '\n'

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

using namespace std;

struct Cord {
    int x, y;
};

// Time Complexity: O(V + E)
int dfs(vector<vector<char>>& adj, vector<vector<bool>>& visited, Cord v, int k, int depth = 0) {
    if (depth >= k) return 1;
    // pre-visited
    visited[v.x][v.y] = true;

    int answ = 0;

    for (int d = 0; d < 4; d++) {
        Cord e = {v.x+dx[d], v.y+dy[d]};
        
        if (e.x < 0 || e.x >= adj.size() || e.y < 0 || e. y >= adj[0].size()) continue;

        if (!visited[e.x][e.y] && adj[e.x][e.y] != '#') {
            answ += dfs(adj, visited, e, k, depth+1);
        }
    }
    // post-visited
    visited[v.x][v.y] = false;

    return answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col; char c;
    
    int k;

    cin >> row >> col;
    
    cin >> k;

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
            if (board[i][j] != '#') 
                answ += dfs(board, visited, {i,j}, k);
        }
    }
    
    cout << answ << endl;

    return 0;
}
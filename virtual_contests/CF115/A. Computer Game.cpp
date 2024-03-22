#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int dx[] = {0, 0, 1,-1, 1, 1,-1,-1};
const int dy[] = {1,-1, 0, 0, 1,-1, 1,-1};

int solve() {
    int row = 2; int col; char c;
    
    cin >> col;
    
    char board[row][col];
    
    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(c);
            board[i][j] = c;
        }
    }

    queue<pair<int,int>> operation_order;
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    operation_order.push({0,0});
    visited[0][0] = true;
    
    int x, y;

    while (!operation_order.empty()) {
        pair<int,int> cord = operation_order.front();
        operation_order.pop();

        for (int d = 0; d < 8; d++) {
            x = cord.first+dx[d]; y = cord.second+dy[d];
            if (x >= 0 && x < row && y >= 0 && y < col) {
                if (!visited[x][y]) {
                    if (board[x][y] == '0') {
                        operation_order.push({x,y});
                        visited[x][y] = true;
                    }
                }
            }
        }
    }

    if (visited[1][col-1]) cout << "YES" << endl;
    else cout << "NO" << endl;
    

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
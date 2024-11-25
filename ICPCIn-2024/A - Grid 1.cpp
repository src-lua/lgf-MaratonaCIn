#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

const int MOD = 1e9+7; 
const int dx[] = {0,1};
const int dy[] = {1,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col; char c;
    
    cin >> row >> col;
    
    char board[row][col];
    
    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(c);
            board[i][j] = c;
        }
    }

    vector<vector<int>> dp(row, vector<int>(col, 0));
    queue<pii> operation_order;
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int i, j;

    operation_order.push({0,0});
    dp[0][0] = 1;
    while(!operation_order.empty()){
        auto [x, y] = operation_order.front();
        operation_order.pop();

        for (int d = 0; d < 2; d++) {
            i = x + dx[d]; j = y + dy[d];

            if (i >= row || j >= col) continue;
            if (board[i][j] == '#') continue;

            dp[i][j] += dp[x][y] % MOD;

            if (!visited[i][j]) {
                visited[i][j] = true;
                operation_order.push({i,j});
            }
        }
    }

    cout << dp[row-1][col-1] % MOD;

    return 0;
}
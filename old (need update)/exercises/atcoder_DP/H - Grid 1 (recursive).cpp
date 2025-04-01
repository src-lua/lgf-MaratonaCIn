#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
const int MOD = 1e9+7;

const int MX = 1000;
char board[MX][MX];
vector<vector<int>> dp(MX, vector<int>(MX, -1));


int solve(int r, int c) {

    if (dp[r][c] != -1) return dp[r][c];

    int vertical = 0; if (r>0) if (board[r-1][c] != '#') vertical = solve(r-1, c);
    int horizontal = 0; if (c>0) if (board[r][c-1] != '#') horizontal = solve(r, c-1);

    return dp[r][c] = (vertical+horizontal)%MOD;   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col; char c;
    
    cin >> row >> col;
    
    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(c);
            board[i][j] = c;
        }
    }

    dp[0][0] = 1;
    cout << solve(row-1,col-1);


    return 0;
}
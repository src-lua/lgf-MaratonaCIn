#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    if (board[0][0] < board[0][1]) { // esquerda para direita crescente
        if(board[0][0] < board[1][0]) cout << 0 << endl;
        else cout << 3 << endl;
    }
    else {
        if(board[0][0] < board[1][0]) cout << 1 << endl;
        else cout << 2 << endl;
    }

    return 0;
}
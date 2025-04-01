#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

bool placeable(vector<string>&board, int i, int j) {
    for (int r = i; r >= 0; r--) {
        if (board[r][j] == 'Q') return false;
    }

    for (int c = j; c >= 0; c--) {
        if (board[i][c] == 'Q') return false;
    }

    int c1 = j;
    int c2 = j;
    for (int r = i-1; r >= 0; r--) {
        if (--c1 >= 0) if (board[r][c1] == 'Q') return false;
        if (++c2 <  8) if (board[r][c2] == 'Q') return false;
    }

    return true;
}

int solve(int i, vector<string>& board) {
    if (i == 8) return 1;

    ll answ = 0;

    for (int j = 0; j < 8; j++) {
        if (board[i][j] != '*' && placeable(board, i, j)) {
            board[i][j] = 'Q';
            answ += solve(i+1, board);
            board[i][j] = '.';
        }
    }

    return answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> board(8, string());

    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    cout << solve(0, board);

    return 0;
}
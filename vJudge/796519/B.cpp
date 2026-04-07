/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://vjudge.net/contest/796519#problem/B
 * Status:      AC
 * Created:     14-03-2026 09:15:55
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<string> board(n);
    for (auto &row : board) cin >> row;
    
    for (int i = 0; i < n; i++) {
        set<char> s1, s2;
        for (int j = 0; j < n; j++) {
            s1.insert(board[i][j]);
            s2.insert(board[j][i]);
        }
        if (s1.size() != n || s2.size() != n) {
            cout << "No\n";
            return 0;
        }
    }

    array<int, 36> order = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U' ,'V', 'W', 'X', 'Y', 'Z'};

    for (int i = 0; i < n; i++) {
        if (board[i][0] != order[i] || board[0][i] != order[i]) {
            cout << "Not Reduced\n";
            return 0;
        }
    }
    
    cout << "Reduced\n";
    return 0;
}

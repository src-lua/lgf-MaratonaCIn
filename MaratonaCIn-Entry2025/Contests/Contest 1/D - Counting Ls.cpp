#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int dx[] = {1, -1, 1, -1};
const int dy[] = {1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    char c;

    cin >> n;

    vector<vector<char>> board(n, vector<char>(n));

    vector<int> rows(n, 0);
    vector<int> cols(n, 0);

    for (int i = 0; i < n; i++) {
        cin.get();
        for (int j = 0; j < n; j++) {
            cin.get(c);
            board[i][j] = c;
            if (c == 'o') {
                rows[i]++;
                cols[j]++;
            }
        }
    }

    long long answ = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'o') {
                answ += (rows[i] - 1) * (cols[j] - 1);
            }
        }
    }

    cout << answ << '\n';

    return 0;
}
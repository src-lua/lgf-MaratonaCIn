#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col; char c;
    
    cin >> row >> col;
    
    vector<vector<char>> board(row, vector<char>(col));
    
    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(c);
            board[i][j] = c;
        }
    }

    vector<vector<int>> row_board(row, vector<int>(col));
    vector<vector<int>> col_board(row, vector<int>(col));

    vector<int> dict;
    dict.push_back(0);
    int idx = 1;
    int sum = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == '#') {
                row_board[i][j] = 0;
                dict.push_back(sum);
                sum = 0;
                idx++;

            }
            else {
                row_board[i][j] = idx;
                sum++;
            }
        }
        dict.push_back(sum);
        sum = 0;
        idx++;
    }

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (board[j][i] == '#') {
                col_board[j][i] = 0;
                dict.push_back(sum);
                sum = 0;
                idx++;
            }
            else {
                col_board[j][i] = idx;
                sum++;
            }
        }
        dict.push_back(sum);
        sum = 0;
        idx++;
    }

    int maxsum = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum = dict[row_board[i][j]] + dict[col_board[i][j]] - 1;
            maxsum = max(maxsum, sum);
        }
    }

    cout << maxsum << endl;

    return 0;
}
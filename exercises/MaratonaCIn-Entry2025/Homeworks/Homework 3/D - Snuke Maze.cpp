#include <bits/stdc++.h>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col;

    cin >> row; cin >> col;

    char board[row+2][col+2];

    for (int i = 1; i < row+1; i++) {
        cin.get();
        for (int j = 1; j < col+1; j++) {
            cin.get(board[i][j]);
        }
    }

    queue<pair<int,int>> operation_order;
    pair<int,int> cord;
    vector<vector<bool>> visited(row+2, vector<bool>(col+2, false));
    char expected_order[6] = {'s','n','u','k','e','s'};
    // char expected_order[6] = {'e','k','u','n','s','e'};
    vector<vector<int>> expected(row+2, vector<int>(col+2));

    if (board[1][1] != 's') {

        cout << "No";
        return 0;
    }

    operation_order.push({row,col});
    visited[row][col] = true;
    
    for (int i = 0; i < 5; i++) {
        if (board[row][col] == expected_order[i]) {
            expected[row][col] = i;
        }
    }

    while(!operation_order.empty()) {
        
        int i = operation_order.front().first;
        int j = operation_order.front().second;
        operation_order.pop();

        for (int a = 0; a < 4; a++) {
            if (i+dx[a] == 1 && j+dy[a] == 1) {
                cout << "Yes";
                return 0;
            }
            if (!visited[i+dx[a]][j+dy[a]]) {
                if (board[i+dx[a]][j+dy[a]] == expected_order[expected[i][j]+1]) {
                    operation_order.push({i+dx[a],j+dy[a]});
                    expected[i+dx[a]][j+dy[a]] = expected[i][j] + 1;
                    if (expected[i+dx[a]][j+dy[a]] == 5) expected[i+dx[a]][j+dy[a]] = 0; 
                    visited[i+dx[a]][j+dy[a]] = true;
                }
            }
        }
    }

    cout << "No";

    return 0;
}
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int row, col;

bool check(int m, const vector<vector<int>>& board) {
    int x, y;

    queue<pair<int,int>> operation_order;
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    operation_order.push({0,0});
    visited[0][0] = true;

    while (!operation_order.empty()) {
        pair<int,int> cord = operation_order.front();
        operation_order.pop();

        for (int d = 0; d < 4; d++) {
            x = cord.first+dx[d]; y = cord.second+dy[d];
            if (x >= 0 && x < row && y >= 0 && y < col) {
                if (!visited[x][y]) {
                    if (board[x][y] <= m) {
                        operation_order.push({x,y});
                        visited[x][y] = true;
                    }
                }
            }
        }
    }
    
    return visited[row-1][col-1];
}

int binarySearch(int l, int r, const vector<vector<int>>& board)
{
    int answ;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (!check(m, board))
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            answ = m;
            r = m - 1;
        }
    }
 
    return answ;
}

int solve() {

    cin >> row >> col;

    vector<vector<int>> board(row, vector<int>(col, min(row,col)+1));
    vector<vector<pii>> positions(min(row,col)+1);

    int lilipads; cin >> lilipads;
    int c = 0; // up to 1e18

    int x, y;
    for (int i = 0; i < lilipads; i++) {
        cin >> x >> y;
        board[--x][--y] = 1;
        positions[1].push_back({x,y});
        c++;
    }

    // MODIFIED BFS TO BUILD THE BOARD WITH NUMBERS OF EACH STEP
    int k = 1;
    while (c != row*col) {
        for (auto cord: positions[k]) {
            for (int d = 0; d < 4; d++) {
                x = cord.first+dx[d]; y = cord.second+dy[d];
                if (x >= 0 && x < row && y >= 0 && y < col) {
                    if (board[x][y] == min(row,col)+1) {
                        board[x][y] = k+1;
                        positions[k+1].push_back({x,y});
                        c++;
                    }
                }
            }
        } k++;
    }

    return binarySearch(0, min(row,col)-1, board);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        cout << solve()-1 << endl;
    }

    return 0;
}
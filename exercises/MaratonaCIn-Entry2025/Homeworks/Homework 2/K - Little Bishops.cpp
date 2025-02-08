#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;

int solve(int i, int j, int n, int d, vector<vector<bool>>& board) {

    if (n >= j) return 1;

    int answ = 0;

    for(int diag = d; diag < i*2-1; diag++) {
        if (j - n > i*2-1) return 0; // If I need to put more bishops than diagonal

        // |0|1|2|3|
        // |4|0|1|2|
        // |5|4|0|1|
        // |6|5|4|0|

        int row, col;

        if (diag < i) {
            row = diag % i;
            col = 0;
        } else {
            row = i-1 ;
            col = diag % i + 1;
        }

        for(; row >= 0 and col < i; row--, col++){        
            if (!board[row][col]) {
                for (int r = row, c = col; r < i && c < i; r++, c++) {
                    board[r][c] = true;
                }
                
                answ += solve(i, j, n+1, d+1, board);

                for (int r = row, c = col; r < i && c < i; r++, c++) {
                    board[r][c] = false;
                }
            }
        }


        // |0|1|2|3|
        // |1|2|3|4|
        // |2|3|4|5|
        // |3|4|5|6|

        // if (diag < i) {
        //     row = 0;
        //     col = diag;
        // } else {
        //     row = diag - (i-1);
        //     col = n-1;
        // }

        // while (row <i && col >= 0) {


        //     row++; col--;
        // } 
        
    
    }

    return answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("bishops.txt", "w", stdout);

    cout << "{ ";

    for (int i = 1; i <= 8; i++) {
        for (int j = 0; j <= i*i; j++) {
            vector<vector<bool>> board(i, vector<bool>(i, false));
            cout << solve(i, j, 0, 0, board) << ", " << flush;
        }
        cout << '\n';
    }
    

    cout << "}\n";

    return 0;
}
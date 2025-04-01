#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col; char c;
    
    cin >> row >> col;
    
    vector<vector<ll>> board(row, vector<ll>(col, 0));
    
    for (int i = 0; i < row; i++) {
        cin.get();
        int cnt = 0;
        for (int j = 0; j < col; j++) {
            cin.get(c);
            if (c == '#') board[i][j] = ++cnt;
            else cnt = 0;
        }
    }

    for (int i = 0; i < row; i++) {
        
    }
    

    // vector<vector<ll>> ps(row+1, vector<ll>(col+1, 0));


    // for (int i = 1; i <= row; i++) {
    //     for (int j = 1; j <= col; j++) {
    //         if (board[i-1][j-1] == '.') ps[i][j] = 0;
    //         else ps[i][j] = max(1ll, 1ll + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1]);
    //     }
    // }

    // ll mx = 0ll;

    // for (int i = 1; i <= row; i++) {
    //     for (int j = 1; j <= col; j++) {
    //         mx = max(mx, ps[i][j]);
    //         cout << ps[i][j] << ' ';
    //     } 
    //     cout << endl;
    // }

    // cout << mx;

    return 0;
}
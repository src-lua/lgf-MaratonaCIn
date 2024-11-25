#include <bits/stdc++.h>
 
#define endl '\n'
#define int long long 
 
using namespace std;
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int tc; cin >> tc; while (tc--) {
        int row, col; cin >> row >> col;
 
        int pos = (max(row, col) * max(row, col) - max(row, col) + 1);
 
        if ((max(row,col) % 2 == 0 && col > row) || (max(row, col) % 2 != 0 && row > col)) {
            pos -= abs(row-col);
        }
        else if (row != col) {
            pos += abs(row-col);
        }
 
        cout << pos << endl;
    }
 
    return 0;
}
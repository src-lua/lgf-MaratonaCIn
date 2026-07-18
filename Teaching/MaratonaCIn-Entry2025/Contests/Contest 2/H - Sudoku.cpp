#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;

    // 0*n -> linhas
    // 1*n -> colunas
    // 2*n -> quadrados
    vector<set<int>> arr(3*n);

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int idx = 0;

    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {
            arr[idx].insert(board[i][j]);
        }
        idx++;
    }

    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {
            arr[idx].insert(board[j][i]);
        }
        idx++;
    }

    int sn = sqrt(n);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i * i < n; i++) {
            for (int j = 0; j * j < n; j++) {
                arr[idx].insert(board[i + (int(k / sn) * sn)][j + ((k % sn) * sn)]);
            }
        }
        idx++;
    }

    for (int i = 0; i < 3*n; i++) {
        if (arr[i].size() != n) {
            cout << "no" << endl;
            return 0;
        }
    }
    
    cout << "yes" << endl;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    
    int board[n][n];

    int x;

    vector<int> diagonais(2*n-1, INT_MAX);


    int idx = n-1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            diagonais[idx+j] = min(diagonais[idx+j], x);
        }
        idx--;
    }

    int answ = 0;

    for (auto e : diagonais) {
        if (e < 0) answ -= e;
    }

    cout << answ << '\n';

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
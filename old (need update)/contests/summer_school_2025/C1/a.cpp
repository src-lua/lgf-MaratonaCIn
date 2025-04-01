#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, m; cin >> n >> m;

    if (n*m % 2 == 1) {
        char k = 'B';

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << k;
                k == 'B' ? k = 'W' : k = 'B';
            }
            cout << endl;
        }
    }

    else {
        char k = 'B';

        for (int i = 0; i < n; i++) {
            if (i == 1) k = 'B';
            for (int j = 0; j < m; j++) {
                if (i == 0 && (j == 1 || j == 0)) k = 'B';
                cout << k;
                k == 'B' ? k = 'W' : k = 'B';
            }
            cout << endl;
        }
    }

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
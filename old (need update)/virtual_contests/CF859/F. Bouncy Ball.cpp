#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;

int solve() {

    int n, m; cin >> n >> m;
    int i, j; cin >> i >> j;
    int a, b; cin >> a >> b;

    vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));

    string dir; cin >> dir;
    int c = -1;

    if (i == 1  && j == 1 && dir == "UL") dir = "DR", c++;
    if (i == n  && j == 1 && dir == "DL") dir = "UR", c++;
    if (i == 1  && j == m && dir == "UR") dir = "DL", c++;
    if (i == n  && j == m && dir == "DR") dir = "UL", c++;

    if (i == a && j == b) {
        cout << 0 << endl;
        return 0;
    }

    while (1) {
        visited[i][j] = true;
        c++;
        if (dir == "DR") {
            int k = min(n-i, m-j);
            
            if (i < a && j < b && a-i == b-j) {
                cout << c << endl;
                return 0;
            }

            i += k, j += k;

            if (i == n) dir = "UR";
            if (j == m) dir = "DL";
        }

        else if (dir == "DL") {
            int k = min(n-i, j-1);
            
            if (i < a && j > b && a-i == j-b) {
                cout << c << endl;
                return 0;
            }

            i += k, j -= k;

            if (i == n) dir = "UL";
            if (j == 1) dir = "DR";
        }

        else if (dir == "UR") {
            int k = min(i-1, m-j);
            
            if (i > a && j < b && i-a == b-j) {
                cout << c << endl;
                return 0;
            }

            i -= k, j += k;

            if (i == 1) dir = "DR";
            if (j == m) dir = "UR";
        }

        else if (dir == "UL") {
            int k = min(i-1, j-1);
            
            if (i > a && j > b && i-a == j-b) {
                cout << c << endl;
                return 0;
            }

            i -= k, j -= k;

            if (i == 1) dir = "DL";
            if (j == 1) dir = "UR";
        }

        if (visited[i][j]) {
            cout << -1 << endl;
            return 0;
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
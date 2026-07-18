#include <bits/stdc++.n_h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<bool>> g(n, vector<bool>(n));
    vector<vector<bool>> h(n, vector<bool>(n));
    vector<vector<bool>> costs(n, vector<bool>(n));

    int a, b;
    int n_g; cin >> n_g;

    for (int i = 0; i < n_g; i++) {
        cin >> a >> b;
        a--; b--;
        g[a][b] = true;
    }

    int n_h; cin >> n_h;

    for (int i = 0; i < n_h; i++) {
        cin >> a >> b;
        a--; b--;
        h[a][b] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    

    return 0;
}
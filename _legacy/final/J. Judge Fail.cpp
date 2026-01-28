#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(10) << fixed;

    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> maratoneiros(m);

    int x;
    for (int i = 0; i < m; i++){
        cin >> x;

        maratoneiros[i] = vector<int>(x);
        for (int j = 0; j < x; j++) {
            cin >> maratoneiros[i][j];
        }
    }

    vector<double> vereditos(k, 0);

        for (int i = 0; i < n; i++) {
        cin >> x; --x;

        for (auto e : maratoneiros[x]) {
            vereditos[e-1] += 1.0/maratoneiros[x].size();
        }
    }

    for (auto e : vereditos) {
        cout << e << ' ';
    }
    
    

    return 0;
}